# Laboratorio de Semana 2

| Problem                                                                                           | Code Solution                      | Analisys                                                                                     |
| ------------------------------------------------------------------------------------------------- | ---------------------------------- | -------------------------------------------------------------------------------------------- |
| [A. Sasha and the Beautiful Array (Codeforces)](https://codeforces.com/problemset/problem/1929/A) | [sasha_array.cpp](sasha_array.cpp) | [A. Sasha and the Beautiful Array (Codeforces)](#a-sasha-and-the-beautiful-array-codeforces) |
| [RKS - RK Sorting](https://www.spoj.com/problems/RKS/)                                            | [rks.cpp](rks.cpp)                 |

# A. Sasha and the Beautiful Array (Codeforces)

The sum of the values $(a_i − a_{i−1})$ for all integers i from 2 to n is a [Telescoping Series](https://en.wikipedia.org/wiki/Telescoping_series)

$$\sum_{n=2}^{N} (a_{i} - a_{i-1}) = (a_{n} - a_{1})$$

Thus, by putting the maximum value of the array in the last position, and the minimum value at the beginning of the array you can obtain the maximum beauty of the array a, if you rearrange its elements in this way (increasingly ordered).

# RKS Sorting

Since we only need the frequency of occurrence and the rate of first occurrence to sort the message, we only store the keys together with their frequency in the array (`Array<Tuple<key: int, position: int>>`) sorted by their first occurrence. That is, we store the key the first time, and the following ones we increase the frequency. In this way we sort fewer elements.

We use a linear search to increase the frequency (if the key exists) or add the key (if it does not exist), and a kind of cache (`Tuple<key: int, position: int>`) to avoid unnecessary searches by caching the last element read and its position.

