
# Function to calculate the factorial of a number
def factorial(number):
    if number <= 1:
        return 1
    else:
        # Recursive call to calculate factorial
        number = number * factorial(number - 1)
        return number


# Function to perform linear search in a list
def linear_search(list, key, index=0):
    if list is None:
        return -1
    if index == len(list):
        return -1
    if list[index] == key:
        return index
    # Recursive call to search for key in the remaining list
    return linear_search(list, key, index + 1)


# Function to perform binary search in a sorted list
def binary_search(list, key, starting=None, ending=None):
    if starting is None:
        starting = 0
    if ending is None:
        ending = len(list) - 1
    
    while starting <= ending:
        midpoint = (starting + ending) // 2
        if list[midpoint] == key:
            # Key found at midpoint
            return midpoint
        elif list[midpoint] < key:
            # Key is in the right half of the list
            starting = midpoint + 1
        else:
            # Key is in the left half of the list
            ending = midpoint - 1
    
 
    return -1
