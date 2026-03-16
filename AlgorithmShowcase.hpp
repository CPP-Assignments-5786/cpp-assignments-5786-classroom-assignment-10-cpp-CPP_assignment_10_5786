/**
 * @file AlgorithmShowcase.hpp
 * @brief Free functions showcasing various STL algorithm categories
 *
 * Each function demonstrates a specific category of STL algorithms.
 *
 * Topics covered:
 * - Permutations (next_permutation, prev_permutation)
 * - IO iterators (ostream_iterator, istream_iterator)
 * - Numeric algorithms (iota, accumulate, inner_product, partial_sum)
 * - Miscellaneous algorithms
 */

#ifndef ALGORITHMSHOWCASE_HPP
#define ALGORITHMSHOWCASE_HPP

#include <vector>
#include <string>
#include <iostream>

namespace datatools {

    // ============================================================
    //                      PERMUTATIONS
    // ============================================================

    /**
     * @brief Generate all permutations of a vector of integers
     * The input is sorted first to ensure all permutations are generated.
     * @param nums The input vector (passed by value, sorted internally)
     * @return A vector of vectors, each being one permutation
     */
    std::vector<std::vector<int>> allPermutations(std::vector<int> nums);

    /**
     * @brief Get the next permutation of a vector
     * @param nums The input vector (modified in-place)
     * @return true if a next permutation exists, false if wrapped around
     */
    bool nextPermutation(std::vector<int>& nums);

    /**
     * @brief Get the previous permutation of a vector
     * @param nums The input vector (modified in-place)
     * @return true if a previous permutation exists, false if wrapped around
     */
    bool prevPermutation(std::vector<int>& nums);

    // ============================================================
    //                     IO ITERATORS
    // ============================================================

    /**
     * @brief Print a vector to an output stream using ostream_iterator
     * @param data The vector to print
     * @param os The output stream
     * @param delimiter Separator between elements (default: " ")
     */
    void printWithIterator(const std::vector<int>& data,
                           std::ostream& os,
                           const std::string& delimiter = " ");

    /**
     * @brief Print a vector of doubles with ostream_iterator
     */
    void printDoublesWithIterator(const std::vector<double>& data,
                                   std::ostream& os,
                                   const std::string& delimiter = " ");

    /**
     * @brief Read integers from an input stream using istream_iterator
     * @param is The input stream
     * @return Vector of integers read
     */
    std::vector<int> readFromStream(std::istream& is);

    /**
     * @brief Copy elements from one vector to an output stream, filtered
     * Only copies elements satisfying the predicate.
     * @param data The input vector
     * @param os The output stream
     * @param pred The predicate
     * @param delimiter Separator
     */
    void printFiltered(const std::vector<int>& data,
                       std::ostream& os,
                       std::function<bool(int)> pred,
                       const std::string& delimiter = " ");

    // ============================================================
    //                   NUMERIC ALGORITHMS
    // ============================================================

    /**
     * @brief Generate a vector of N consecutive integers starting from start
     * @param count Number of elements
     * @param start Starting value
     * @return Vector of consecutive integers
     */
    std::vector<int> generateSequence(int count, int start = 0);

    /**
     * @brief Compute running totals of a vector
     * @param data The input vector
     * @return Vector of partial sums
     */
    std::vector<int> runningTotal(const std::vector<int>& data);

    /**
     * @brief Compute the inner product (dot product) of two int vectors
     * @param a First vector
     * @param b Second vector
     * @return The inner product
     * @throws std::invalid_argument if sizes differ
     */
    int dotProduct(const std::vector<int>& a, const std::vector<int>& b);

    // ============================================================
    //              ERASE-REMOVE IDIOM SHOWCASE
    // ============================================================

    /**
     * @brief Remove all occurrences of a value from a vector
     * @param data The vector (modified in-place)
     * @param value The value to remove
     * @return Number of elements removed
     */
    int eraseValue(std::vector<int>& data, int value);

    /**
     * @brief Remove all elements satisfying a predicate from a vector
     * @param data The vector (modified in-place)
     * @param pred The predicate
     * @return Number of elements removed
     */
    int eraseIf(std::vector<int>& data, std::function<bool(int)> pred);

    /**
     * @brief Remove consecutive duplicates from a sorted vector
     * @param data The vector (should be sorted, modified in-place)
     */
    void uniqueInPlace(std::vector<int>& data);

} // namespace datatools

#endif // ALGORITHMSHOWCASE_HPP