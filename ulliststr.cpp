#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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

    (head_->val)[0] == val;
    head_->last = 1;

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

  }

  else {
    tail_->val[(tail_->last)] = val;
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

    (head_->val)[ARRSIZE-1] == val;
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

  }

  else {
    head_->val[(head_->first - 1)] = val;
    head_->first--;
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
  if (tail_->last == 1){
    Item* temp_ = tail_;
    tail_ = tail_->prev;
    delete temp_;
    size_--;
    if (tail_ == nullptr){
      head_ = nullptr;
    }
    else{
      tail_->next = nullptr;
    }
  }

  else{
    tail_->val[tail_->last] = "";
    tail_->last--;
    size_ -= 1;
  }
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
  if (loc >= size_){
    return NULL;
  }

  else{
    size_t counter = 0;
    Item* currItem = head_;
    while (counter < loc){
      if ((currItem->last - currItem->first) + counter >= loc){
        counter += (currItem->last - currItem->first);
        currItem = currItem->next;
        continue;
      }

      else{
        return &(currItem->val[loc - counter]);
      }
    }
  }
}
