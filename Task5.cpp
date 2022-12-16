#include <iostream>
#include <vector>

int main() {
    //vector will be on the stack, but the array it uses internally to store the items will be on the heap. 
    //its elements are allocated on the heap
    std::vector<int> vector;

    // method push_back adds an element to the end
    for (int i = 1; i <= 10; i++) {
        vector.push_back(i);
    }

    // Removes from the vector either a single element(position) or a range of elements([first, last)).
     // erase the first 2 elements:
    vector.erase(vector.begin(), vector.begin() + 2);
    // erase the 4th element
    vector.erase(vector.begin() + 3);

    //The vector is extended by inserting new elements before the element at the specified position,
    //effectively increasing the container size by the number of elements inserted.
    //vector_name.insert(position, val)
    vector.insert(vector.begin() + 5, 1);
 
    //emplace_back also adds an element to the end, but without copying or moving an object
    vector.emplace_back(1);
    // constructs the elements in place.     emplace_back("element");
    // creates a new object and then copies (or moves) that object.     
    //push_back(ExplicitDataType{ "element" });

    //resizes the container so that it contains n elements.
    //if n is smaller than the current container size, the content is reduced to its first n elements.
    //if n is greater than the current container size, the content is expanded by inserting at the end
    //as many elements (of certain value or 0) as needed to reach a size of n.
    vector.resize(5);       //
    vector.resize(8, 100);  //

    //Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
    //This capacity is not necessarily equal to the vector size.
    //It can be equal or greater, with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.
    std::cout << "capacity: " << vector.capacity() << std::endl;

    //Requests that the vector capacity be at least enough to contain n elements.
    //This function has no effect on the vector size and cannot alter its elements.
    vector.reserve(20);

    //Requests the container to reduce its capacity to fit its size.
    vector.shrink_to_fit();
    //capacity after method shrink_to_fit
    std::cout << "capacity: " << vector.capacity() << std::endl;

    for (size_t i = 0; i < vector.size(); i++) {
        // Access element []. Returns a reference to the element at position n in the vector container.
        std::cout << vector[i] << std::endl;
        // Assigns new contents to the container, replacing its current contents
        vector[i] = 5;
    }

    // Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
    vector.clear();
}