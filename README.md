# How to calculate the complexity of an algorithm

## NOTE ⚠️

Remember that we care about the worst-case with Big O so that we will take the maximum possible runtime.

- `t` refers to the time that a statement takes.

#

## <font color="#DAF7A6">1. Sequential Statements</font>

- Each statement takes constant time O(1)
- If we add up all statements’ time it will still be `O(1)`
- `T(n) = t(statement1) +t(statement2) + ... + t(statementN);`

```
function squareSum(a, b, c) {
  const sa = a * a;
  const sb = b * b;
  const sc = c * c;
  const sum = sa + sb + sc;
  return sum;
}
```

## <font color="#DAF7A6">2. Conditional Statements</font>

- The if block has a runtime of O(n log n)
- The else block has a runtime of O(1)
- `T(n) = Max([t(statement1) + t(statement2)], [t(statement3)])`
- O([n * log(n)], [n]) =>` O(n log n)`

```
if (isValid) {
  statement1;
  statement2;
} else {
  statement3;
}
```

## <font color="#DAF7A6">2. Loop Statements</font>

### <font color="#FFC300">Linear time loops</font>

- We find out the runtime of the block inside them and multiply it by the number of times the program will repeat the loop.
- `T(n) = n \* [ t(statement1) + t(statement2) ]`
- All loops that grow proportionally to the input size have a linear time complexity O(n). If you loop through only half of the array, that’s still O(n). Remember that we drop the constants so `1/2 n => O(n)`

```
for (let i = 0; i < n; i++) {
  statement1;
  statement2;
}
```

### <font color="#FFC300">Constant time loops</font>

- If a constant number bounds the loop, let’s say 4 (or even 400). Then, the runtime is constant `O(4) -> O(1)`. See the following example.
- That code is `O(1)` because it no longer depends on the input size. It will always run statement 1 and 2 four times.

```
for (let i = 0; i < 4; i++) {
  statement1;
  statement2;
}
```

### <font color="#FFC300">Logarithmic time loops</font>

- This function divides the array by its middle point on each iteration. The while loop will execute the amount of times that we can divide array.length in half. We can calculate this using the log function. E.g. If the array’s length is 8, then we the while loop will execute 3 times because `log2(8) = 3.` (Binary Search)

```
function fn1(array, target, low = 0, high = array.length - 1) {
  let mid;
  while ( low <= high ) {
    mid = ( low + high ) / 2;
    if ( target < array[mid] )
      high = mid - 1;
    else if ( target > array[mid] )
      low = mid + 1;
    else break;
  }
  return mid;
}
```

### <font color="#FFC300">Nested time loops</font>

- Assuming the statements from 1 to 3 are O(1), we would have a runtime of `O(n * m)`. If instead of m, you had to iterate on n again, then it would be `O(n^2)`.
- `T(n) = n * [t(statement1) + m * t(statement2...3)]`

```
for (let i = 0; i < n; i++) {
  statement1;

  for (let j = 0; j < m; j++) {
    statement2;
    statement3;
  }
}
```

# Lessons in order 📕

- Nodes
- Single Linked List 1
- Single Linked List 2

# Have fun coding 🚀
