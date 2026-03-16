/**
 * @file SetOperations.hpp
 * @brief Functions demonstrating STL set algorithms
 *
 * These functions work on sorted vectors and demonstrate the
 * set algorithms from <algorithm>.
 *
 * Topics covered:
 * - std::set_union
 * - std::set_intersection
 * - std::set_difference
 * - std::set_symmetric_difference
 * - std::merge
 * - std::includes
 */

#ifndef SETOPERATIONS_HPP
#define SETOPERATIONS_HPP

#include <vector>
#include <string>

namespace datatools {

    /**
     * @brief Compute the union of two sorted vectors
     * @param a First sorted vector
     * @param b Second sorted vector
     * @return A sorted vector containing all unique elements from both
     */
    std::vector<int> setUnion(const std::vector<int>& a, const std::vector<int>& b);

    /**
     * @brief Compute the intersection of two sorted vectors
     * @param a First sorted vector
     * @param b Second sorted vector
     * @return A sorted vector containing elements common to both
     */
    std::vector<int> setIntersection(const std::vector<int>& a, const std::vector<int>& b);

    /**
     * @brief Compute the difference (a - b) of two sorted vectors
     * @param a First sorted vector
     * @param b Second sorted vector
     * @return A sorted vector containing elements in a but not in b
     */
    std::vector<int> setDifference(const std::vector<int>& a, const std::vector<int>& b);

    /**
     * @brief Compute the symmetric difference of two sorted vectors
     * @param a First sorted vector
     * @param b Second sorted vector
     * @return A sorted vector of elements in either but not both
     */
    std::vector<int> setSymmetricDifference(const std::vector<int>& a, const std::vector<int>& b);

    /**
     * @brief Merge two sorted vectors into one sorted vector
     * @param a First sorted vector
     * @param b Second sorted vector
     * @return A merged sorted vector (may contain duplicates)
     */
    std::vector<int> mergeSorted(const std::vector<int>& a, const std::vector<int>& b);

    /**
     * @brief Check if sorted vector a includes all elements of sorted vector b
     * @param a The potential superset
     * @param b The potential subset
     * @return true if a includes all elements of b
     */
    bool includes(const std::vector<int>& a, const std::vector<int>& b);

    // ---- String versions ----

    /**
     * @brief Compute the union of two sorted string vectors
     */
    std::vector<std::string> setUnionStr(const std::vector<std::string>& a,
                                          const std::vector<std::string>& b);

    /**
     * @brief Compute the intersection of two sorted string vectors
     */
    std::vector<std::string> setIntersectionStr(const std::vector<std::string>& a,
                                                 const std::vector<std::string>& b);

} // namespace datatools

#endif // SETOPERATIONS_HPP