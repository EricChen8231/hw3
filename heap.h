#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <cmath>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> array;
  PComparator c;
  int m;
};

// Add implementation of member functions here
// We will start top() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
T const &Heap<T, PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if (empty())
  {
    throw std::out_of_range("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return array[0];
}

// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if (empty())
  {
    throw std::out_of_range("Heap is empty");
  }
  std::swap(array[0], array[size() - 1]);
  array.pop_back();
  int index = 0;
  while (true)
  {
    int pref_child = index * m + 1;
    if (pref_child >= size())
    {
      return;
    }
    int end = std::min(pref_child + m, static_cast<int>(size()));
    for (int i = pref_child + 1; i < end; i++)
    {
      if (c(array[i], array[pref_child]))
      {
        pref_child = i;
      }
    }
    if (c(array[pref_child], array[index]))
    {
      std::swap(array[pref_child], array[index]);
      index = pref_child;
    }
    else
    {
      return;
    }
  }
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){
}

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m(m), c(c)
{
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return array.size();
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return array.empty();
}
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &item)
{
  array.push_back(item);
  int index = array.size() - 1;
  while ((index > 0) && (c(array[index], array[(index - 1) / m])))
  {
    std::swap(array[index], array[(index - 1) / m]);
    index = ((index - 1) / m);
  }

}
#endif

