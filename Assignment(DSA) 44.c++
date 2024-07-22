set

1. Find the total number of elements of the set container.
2. Using inbuilt function and insert an element to the set container.
3. Erase an element from a set.
4. Checks whether the set is empty or not.if it is empty insert 5 elements in the set
5. Make a c++ program to insert unique element in set
6. How to find the lower bound of any desired element from the set.
7. how to find the upper bound of any desired element from the set.
8. Create a function to search the element in the set.
9. Converting String into Set in C++ STL
10. You have a set of integer s, which originally contains all the numbers from 1 to n.
Unfortunately, due to some error, one of the numbers in s got duplicated to another
number in the set, which results in repetition of one number and loss of another
number.You are given an integer array nums representing the data status of this set
after the error.Find the number that occurs twice and the number that is missing and return them in the form of an array.

Solution:-

1. #include <iostream>
#include <set>

int main() {
    std::set<int> mySet = {1, 2, 3, 4, 5};
    std::cout << "Total number of elements: " << mySet.size() << std::endl;
    return 0;
}

2. #include <iostream>
#include <set>

int main() {
    std::set<int> mySet = {1, 2, 3};
    mySet.insert(4);  // Inserting an element
    for (int x : mySet) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}

3. #include <iostream>
#include <set>

int main() {
    std::set<int> mySet = {1, 2, 3, 4, 5};
    mySet.erase(3);  // Erasing an element
    for (int x : mySet) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}

4. #include <iostream>
#include <set>

int main() {
    std::set<int> mySet;
    if (mySet.empty()) {
        for (int i = 1; i <= 5; ++i) {
            mySet.insert(i);
        }
    }
    for (int x : mySet) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}

5. #include <iostream>
#include <set>

int main() {
    std::set<int> mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    mySet.insert(2);  // Duplicate, will not be inserted
    for (int x : mySet) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}

6. #include <iostream>
#include <set>

int main() {
    std::set<int> mySet = {1, 3, 5, 7, 9};
    auto it = mySet.lower_bound(4);  // Lower bound of 4
    if (it != mySet.end()) {
        std::cout << "Lower bound of 4: " << *it << std::endl;
    } else {
        std::cout << "No lower bound found." << std::endl;
    }
    return 0;
}

7. #include <iostream>
#include <set>

int main() {
    std::set<int> mySet = {1, 3, 5, 7, 9};
    auto it = mySet.upper_bound(4);  // Upper bound of 4
    if (it != mySet.end()) {
        std::cout << "Upper bound of 4: " << *it << std::endl;
    } else {
        std::cout << "No upper bound found." << std::endl;
    }
    return 0;
}

8. #include <iostream>
#include <set>

bool searchElement(const std::set<int>& s, int element) {
    return s.find(element) != s.end();
}

int main() {
    std::set<int> mySet = {1, 2, 3, 4, 5};
    int element = 3;
    if (searchElement(mySet, element)) {
        std::cout << element << " is in the set." << std::endl;
    } else {
        std::cout << element << " is not in the set." << std::endl;
    }
    return 0;
}

9. #include <iostream>
#include <set>
#include <string>

std::set<char> stringToSet(const std::string& str) {
    return std::set<char>(str.begin(), str.end());
}

int main() {
    std::string str = "hello";
    std::set<char> charSet = stringToSet(str);
    for (char c : charSet) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    return 0;
}

10. #include <iostream>
#include <vector>
#include <set>

std::vector<int> findErrorNums(const std::vector<int>& nums) {
    std::set<int> numSet;
    int duplicated = -1, missing = -1;

    for (int num : nums) {
        if (numSet.count(num)) {
            duplicated = num;
        }
        numSet.insert(num);
    }

    for (int i = 1; i <= nums.size(); ++i) {
        if (numSet.count(i) == 0) {
            missing = i;
            break;
        }
    }

    return {duplicated, missing};
}

int main() {
    std::vector<int> nums = {1, 2, 2, 4};
    std::vector<int> result = findErrorNums(nums);
    std::cout << "Duplicated: " << result[0] << ", Missing: " << result[1] << std::endl;
    return 0;
}
