
#include <stdio.h>

int main(){

    

    return 0;
}

/*

<?php
// PHP program to implement
// iterative Binary Search

// An iterative binary search 
// function
function binarySearch($arr, $low, 
                      $high, $x)
{
    while ($low <= $high)
    {
        $mid = $low + ($high - $low) / 2;

        // Check if x is present at mid
        if ($arr[$mid] == $x)
            return floor($mid);

        // If x greater, ignore
        // left half
        if ($arr[$mid] < $x)
            $low = $mid + 1;

        // If x is smaller, 
        // ignore right half
        else
            $high = $mid - 1;
    }

    // If we reach here, then 
    // element was not present
    return -1;
}

// Driver Code
$arr = array(2, 3, 4, 10, 40);
$n = count($arr);
$x = 10;
$result = binarySearch($arr, 0, 
                       $n - 1, $x);
if(($result == -1))
echo "Element is not present in array";
else
echo "Element is present at index ", 
                            $result;

?>

*/