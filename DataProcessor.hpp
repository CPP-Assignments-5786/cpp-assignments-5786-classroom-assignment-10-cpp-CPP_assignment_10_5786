/**
 * @file DataProcessor.hpp
 * @brief Class for numeric data processing using STL algorithms
 *
 * This class stores a vector of doubles and provides various
 * data processing operations implemented with STL algorithms.
 *
 * Topics covered:
 * - sort, stable_sort, partial_sort, nth_element
 * - accumulate, inner_product, partial_sum, iota
 * - transform, for_each, generate
 * - find, find_if, count_if, all_of, any_of, none_of
 * - copy, copy_if, replace_if, fill
 * - remove_if + erase (erase-remove idiom)
 * - reverse, rotate, unique, partition
 * - min_element, max_element, minmax_element
 */

#ifndef DATAPROCESSOR_HPP
#define DATAPROCESSOR_HPP

#include <vector>
#include <string>
#include <functional>

namespace datatools {

    class DataProcessor {
    private:
        std::vector<double> data;

    public:
        // ============ Constructors ============

        /**
         * @brief Default constructor — empty dataset
         */
        DataProcessor();

        /**
         * @brief Constructor from a vector
         * @param values Initial data values
         */
        explicit DataProcessor(const std::vector<double>& values);

        /**
         * @brief Constructor that generates N values using iota
         * Creates a dataset with values: start, start+1, start+2, ...
         * @param count Number of values to generate
         * @param start Starting value (default: 0.0)
         */
        DataProcessor(int count, double start);

        // ============ Getters ============

        const std::vector<double>& getData() const;
        int size() const;
        bool empty() const;

        // ============ Value Modifiers (Sorting) ============

        /**
         * @brief Sort all data in ascending order
         */
        void sort();

        /**
         * @brief Sort all data using a custom comparator
         * @param comp The comparison function
         */
        void sort(std::function<bool(double, double)> comp);

        /**
         * @brief Partially sort: put the smallest K elements at the front (sorted)
         * @param k Number of elements to sort
         */
        void partialSort(int k);

        /**
         * @brief Put the Nth element in its correct sorted position
         * Elements before it are <= it, elements after are >= it.
         * @param n The index (0-based)
         */
        void nthElement(int n);

        // ============ Queries ============

        /**
         * @brief Compute the sum of all elements
         * @return The sum
         */
        double sum() const;

        /**
         * @brief Compute the product of all elements
         * @return The product (1.0 for empty)
         */
        double product() const;

        /**
         * @brief Compute the average of all elements
         * @return The average
         * @throws std::invalid_argument if empty
         */
        double average() const;

        /**
         * @brief Find the minimum value
         * @return The minimum value
         * @throws std::invalid_argument if empty
         */
        double min() const;

        /**
         * @brief Find the maximum value
         * @return The maximum value
         * @throws std::invalid_argument if empty
         */
        double max() const;

        /**
         * @brief Count elements satisfying a predicate
         * @param pred The predicate
         * @return The count
         */
        int countIf(std::function<bool(double)> pred) const;

        /**
         * @brief Check if ALL elements satisfy a predicate
         */
        bool allOf(std::function<bool(double)> pred) const;

        /**
         * @brief Check if ANY element satisfies a predicate
         */
        bool anyOf(std::function<bool(double)> pred) const;

        /**
         * @brief Check if NO element satisfies a predicate
         */
        bool noneOf(std::function<bool(double)> pred) const;

        /**
         * @brief Find the first element satisfying a predicate
         * @param pred The predicate
         * @return The value found
         * @throws std::invalid_argument if not found
         */
        double findIf(std::function<bool(double)> pred) const;

        /**
         * @brief Compute the inner product (dot product) with another dataset
         * @param other The other DataProcessor
         * @return The inner product
         * @throws std::invalid_argument if sizes differ
         */
        double innerProduct(const DataProcessor& other) const;

        // ============ Transformers (for_each / transform) ============

        /**
         * @brief Apply a function to each element (in-place)
         * @param func The transformation function
         */
        void applyTransform(std::function<double(double)> func);

        /**
         * @brief Create a new DataProcessor with transformed values
         * @param func The transformation function
         * @return A new DataProcessor with transformed data
         */
        DataProcessor transformed(std::function<double(double)> func) const;

        /**
         * @brief Compute running totals (partial sums)
         * @return A new DataProcessor with partial sums
         */
        DataProcessor partialSums() const;

        // ============ Movers & Fillers ============

        /**
         * @brief Filter elements satisfying a predicate into a new DataProcessor
         * @param pred The predicate
         * @return A new DataProcessor with matching elements
         */
        DataProcessor filter(std::function<bool(double)> pred) const;

        /**
         * @brief Replace all elements matching a predicate with a new value
         * @param pred The predicate
         * @param newValue The replacement value
         */
        void replaceIf(std::function<bool(double)> pred, double newValue);

        /**
         * @brief Fill all elements with a value
         * @param value The fill value
         */
        void fill(double value);

        /**
         * @brief Generate values using a generator function
         * @param count Number of values to generate (resizes data)
         * @param generator The generator function
         */
        void generate(int count, std::function<double()> generator);

        // ============ Structure Changers ============

        /**
         * @brief Remove all elements satisfying a predicate
         * @param pred The predicate
         * @return Number of elements removed
         */
        int removeIf(std::function<bool(double)> pred);

        /**
         * @brief Remove consecutive duplicates
         * Data should be sorted first for full deduplication.
         */
        void unique();

        /**
         * @brief Reverse the order of elements
         */
        void reverse();

        /**
         * @brief Rotate elements so that the element at position n becomes first
         * @param n The position to rotate to the front
         */
        void rotate(int n);

        /**
         * @brief Partition data: elements satisfying pred come first
         * @param pred The predicate
         * @return The number of elements satisfying the predicate
         */
        int partition(std::function<bool(double)> pred);

        /**
         * @brief Stable partition: like partition but preserves relative order
         * @param pred The predicate
         * @return The number of elements satisfying the predicate
         */
        int stablePartition(std::function<bool(double)> pred);

        // ============ IO / String Conversion ============

        /**
         * @brief Convert data to a string
         * Format: elements separated by the given delimiter.
         * Whole numbers should be formatted without a decimal point (e.g., "5" not "5.000000").
         * @param delimiter The separator string (default: ", ")
         * @return The string representation
         */
        std::string toString(const std::string& delimiter = ", ") const;
    };

} // namespace datatools

#endif // DATAPROCESSOR_HPP