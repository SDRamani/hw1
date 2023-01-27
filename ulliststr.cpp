#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
#include <sstream>

using namespace std;
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  if (tail_ == NULL)
  {
    head_ = new Item();
    tail_ = head_;

    (head_->val)[0] = val;
    head_->last = 1;
    //cout << "is it working?:" <<(head_->val)[0]<< endl;
    size_++;
    return;
  }

  if (tail_->last == ARRSIZE){
    Item* currItem  = tail_;
    tail_->next = new Item();
    tail_ = tail_->next;

    tail_->prev = currItem;
    currItem->next = tail_;
    tail_->val[0] = val;
    tail_->first = 0;
    tail_->last = 1;
    size_++;

  }

  else {
    tail_->val[(tail_->last)] = val;
    //cout << "is it working?:" << tail_->val[(tail_->last)] << endl;
    tail_->last++;
    size_++;
  }
}

void ULListStr::push_front(const std::string& val)
{
  if (head_ == NULL)
  {
    head_ = new Item();
    tail_ = head_;

    head_->val[ARRSIZE-1] = val;
    //cout << head_->val[ARRSIZE-1] << endl;
    head_->last = ARRSIZE;
    head_->first = ARRSIZE-1;
    

    size_++;
    return;
  }

  if (head_->first == 0){
    Item* currItem  = head_;
    head_->prev = new Item();
    head_ = head_->prev;

    head_->next = currItem;
    currItem->prev = head_;
    head_->val[ARRSIZE-1] = val;
    head_->first = 9;
    head_->last = ARRSIZE;
    //cout << "push_front:" << head_val[head_->first] <<endl;

    size_++;

  }

  else {
    //cout << "default" << endl;
    head_->first--;
    head_->val[(head_->first)] = val;
    cout << "val: " << head_->val[(head_->first)] << endl;
    size_++;
  }
}

void ULListStr::pop_front()
{
  
  if (head_->first == ARRSIZE - 1){
    Item* temp_ = head_;
    head_ = head_->next;
    delete temp_;
    size_--;
    if (head_ == nullptr){
      tail_ = nullptr;
    }
    else{
      head_->prev = nullptr;
    }
  }

  else{
    head_->val[head_->first] = "";
    head_->first++;
    size_ -= 1;
  }
}

void ULListStr::pop_back()
{
  cout << "tail_last:" <<tail_->last<<endl;
  if (tail_->last == 1){
    Item* temp_ = tail_;
    tail_ = tail_->prev;
    delete temp_;
    
    cout <<"c" <<size_;
    size_--;
    cout << "c"<<size_;
    
    if (tail_ == nullptr){
      head_ = nullptr;
    }
    
    else{
      tail_->next = nullptr;
    }
  }

  else{
    cout << "hi";
    tail_->val[tail_->last - 1] = "";
    tail_->last--;
    size_ -= 1;
  }
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string const & ULListStr::back() const
{
  return tail_->val[(tail_->last)-1];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc > size_){
    return NULL;
  }

  else{
    size_t counter = 0;
    Item* currItem = head_;
    size_t place = currItem->first;
    //cout << "place:" << place << endl;
    while (counter < loc){
      if (place == ((currItem->last) - 1)){
        //cout << "place1:" << place << " " << endl;
        currItem = currItem->next;
        place = currItem->first;
        counter++;
        //cout << "place2:" << place << " " << endl;
      }
      else{
        counter++;
        place++;
      }
    }
    return &(currItem->val[place]);
  }
}
