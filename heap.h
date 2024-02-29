#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
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
  //Heap(int m = 2, PComparator c = PComparator()) : m(m), comparator(c), size_(0) {}

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

  std::vector<T> heap_vector;
  
  int m;
  PComparator comparator;
  size_t size_;
  

    
  void heapifyUp(int index);
  void heapifyDown(int index);


};

// Add implementation of member functions here


//constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m(m), comparator(c), size_(0) {}

//destructor
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() 
{}



//empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  if(heap_vector.size() == 0)
  {
    return true;
  }
  else{
    return false;
  }
}

//size
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return size_;
}



// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
  throw std::underflow_error("out of scope");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else
  {
    return heap_vector[0];
  }


}



// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
  throw std::underflow_error("out of scope");
  }

  std::swap(heap_vector[0], heap_vector[size_ - 1]);
  heap_vector.pop_back();
  size_--;
  heapifyDown(0);


}


// We will start push() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{

heap_vector.push_back(item);
size_++;
heapifyUp(heap_vector.size()-1);
  
}





template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / m;
        if (comparator(heap_vector[index], heap_vector[parent])) {
            std::swap(heap_vector[index], heap_vector[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(int index) {
    while (true) {
        int left = index * m + 1;
        if (left >= (int)size_) {
            break;
        }
        int right = std::min(left + m, static_cast<int>(size_));
        int next = left;
        for (int i = left + 1; i < right; ++i) {
            if (comparator(heap_vector[i], heap_vector[next])) {
                next = i;
            }
        }
        if (comparator(heap_vector[next], heap_vector[index])) {
            std::swap(heap_vector[next], heap_vector[index]);
            index = next;
        } else {
            break;
        }
    }
}



#endif

