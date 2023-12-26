/**
 * @file relation_definer.hpp
 * @author Rumata888
 * @brief This file contains settings for the General Permutation Relation implementations and (in the future) Lookup
 * implementations
 *
 */
#pragma once
#include <cstddef>
#include <tuple>
namespace proof_system::honk::sumcheck {

/**
 * @brief This class contains an example of how to set PermutationSettings classes used by the
 * GenericPermutationRelationImpl class to specify a concrete permutation
 *
 * @details To create your own permutation:
 * 1) Create a copy of this class and rename it
 * 2) Update all the values with the ones needed for your permutation
 * 3) Update "DECLARE_IMPLEMENTATIONS_FOR_ALL_SETTINGS" and "DEFINE_IMPLEMENTATIONS_FOR_ALL_SETTINGS" to include the new
 * settings
 * 4) Add the relation with the chosen settings to Relations in the flavor (for example,"`
 *   using Relations = std::tuple<sumcheck::GenericPermutationRelation<sumcheck::ExamplePermutationSettings, FF>>;)`
 *
 */
class ExampleTuplePermutationSettings {
  public:
    // This constant defines how many columns are bundled together to form each set. For example, in this case we are
    // bundling tuples of (permutation_set_column_1, permutation_set_column_2) to be a permutation of
    // (permutation_set_column_3,permutation_set_column_4). As the tuple has 2 elements, set the value to 2
    constexpr static size_t COLUMNS_PER_SET = 2;

    /**
     * @brief If this method returns true on a row of values, then the inverse polynomial at this index. Otherwise the
     * value needs to be set to zero.
     *
     * @details If this is true then permutation takes place in this row
     *
     */
    template <typename AllEntities> static inline bool inverse_polynomial_is_computed_at_row(const AllEntities& in)
    {
        return (in.enable_tuple_set_permutation == 1);
    }

    /**
     * @brief Get all the entities for the permutation when we don't need to update them
     *
     * @details The entities are returned as a tuple of references in the following order:
     * - The entity/polynomial used to store the product of the inverse values
     * - The entity/polynomial that switches on the subrelation of the permutation relation that ensures correctness of
     * the inverse polynomial
     * - The entity/polynomial that enables adding a tuple-generated value from the first set to the logderivative sum
     * subrelation
     * - The entity/polynomial that enables adding a tuple-generated value from the second set to the logderivative sum
     * subrelation
     * - A sequence of COLUMNS_PER_SET entities/polynomials that represent the first set (N.B. ORDER IS IMPORTANT!)
     * - A sequence of COLUMNS_PER_SET entities/polynomials that represent the second set (N.B. ORDER IS IMPORTANT!)
     *
     * @return All the entities needed for the permutation
     */
    template <typename AllEntities> static inline auto get_const_entities(const AllEntities& in)
    {

        return std::forward_as_tuple(
            in.tuple_permutation_inverses,   /* The polynomial containing the inverse product*/
            in.enable_tuple_set_permutation, /* The polynomial enabling the product check subrelation */
            in.enable_tuple_set_permutation, /* Enables adding first set to the sum */
            in.enable_tuple_set_permutation, /* Enables adding second set to the sum */
            in.permutation_set_column_3,     /* The first entry in the first set tuple */
            in.permutation_set_column_4,     /* The second entry in the first set tuple */
            in.permutation_set_column_1,     /* The first entry in the second set tuple */
            in.permutation_set_column_2);    /* The second entry in the second set tuple */
    }

    /**
     * @brief Get all the entities for the permutation when need to update them
     *
     * @details The entities are returned as a tuple of references in the following order:
     * - The entity/polynomial used to store the product of the inverse values
     * - The entity/polynomial that switches on the subrelation of the permutation relation that ensures correctness of
     * the inverse polynomial
     * - The entity/polynomial that enables adding a tuple-generated value from the first set to the logderivative sum
     * subrelation
     * - The entity/polynomial that enables adding a tuple-generated value from the second set to the logderivative sum
     * subrelation
     * - A sequence of COLUMNS_PER_SET entities/polynomials that represent the first set (N.B. ORDER IS IMPORTANT!)
     * - A sequence of COLUMNS_PER_SET entities/polynomials that represent the second set (N.B. ORDER IS IMPORTANT!)
     *
     * @return All the entities needed for the permutation
     */
    template <typename AllEntities> static inline auto get_nonconst_entities(AllEntities& in)
    {
        return std::forward_as_tuple(
            in.tuple_permutation_inverses,   /* The polynomial containing the inverse product*/
            in.enable_tuple_set_permutation, /* The polynomial enabling the product check subrelation */
            in.enable_tuple_set_permutation, /* Enables adding first set to the sum */
            in.enable_tuple_set_permutation, /* Enables adding second set to the sum */
            in.permutation_set_column_3,     /* The first entry in the first set tuple */
            in.permutation_set_column_4,     /* The second entry in the first set tuple */
            in.permutation_set_column_1,     /* The first entry in the second set tuple */
            in.permutation_set_column_2);    /* The second entry in the second set tuple */
    }
};

/**
 * @brief This class contains an example of how to set PermutationSettings classes used by the
 * GenericPermutationRelationImpl class to specify a concrete permutation
 *
 * @details To create your own permutation:
 * 1) Create a copy of this class and rename it
 * 2) Update all the values with the ones needed for your permutation
 * 3) Update "DECLARE_IMPLEMENTATIONS_FOR_ALL_SETTINGS" and "DEFINE_IMPLEMENTATIONS_FOR_ALL_SETTINGS" to include the new
 * settings
 * 4) Add the relation with the chosen settings to Relations in the flavor (for example,"`
 *   using Relations = std::tuple<sumcheck::GenericPermutationRelation<sumcheck::ExamplePermutationSettings, FF>>;)`
 *
 */
class ExampleSameWirePermutationSettings {
  public:
    // This constant defines how many columns are bundled together to form each set. For example, in this case we are
    // permuting entries in the column with itself (self_permutation_column), so we choose just one
    constexpr static size_t COLUMNS_PER_SET = 1;

    /**
     * @brief If this method returns true on a row of values, then the inverse polynomial at this index. Otherwise the
     * value needs to be set to zero.
     *
     * @details If this is true then permutation takes place in this row
     *
     */
    template <typename AllEntities> static inline bool inverse_polynomial_is_computed_at_row(const AllEntities& in)
    {
        return (in.enable_single_column_permutation == 1);
    }

    /**
     * @brief Get all the entities for the permutation when we don't need to update them
     *
     * @details The entities are returned as a tuple of references in the following order:
     * - The entity/polynomial used to store the product of the inverse values
     * - The entity/polynomial that switches on the subrelation of the permutation relation that ensures correctness of
     * the inverse polynomial
     * - The entity/polynomial that enables adding a tuple-generated value from the first set to the logderivative sum
     * subrelation
     * - The entity/polynomial that enables adding a tuple-generated value from the second set to the logderivative sum
     * subrelation
     * - A sequence of COLUMNS_PER_SET entities/polynomials that represent the first set (N.B. ORDER IS IMPORTANT!)
     * - A sequence of COLUMNS_PER_SET entities/polynomials that represent the second set (N.B. ORDER IS IMPORTANT!)
     *
     * @return All the entities needed for the permutation
     */
    template <typename AllEntities> static inline auto get_const_entities(const AllEntities& in)
    {

        return std::forward_as_tuple(
            in.single_permutation_inverses,      /* The polynomial containing the inverse product*/
            in.enable_single_column_permutation, /* The polynomial enabling the product check subrelation */
            in.enable_first_set_permutation,     /* Enables adding first set to the sum */
            in.enable_second_set_permutation,    /* Enables adding second set to the sum */
            in.self_permutation_column,          /* The first set column */
            in.self_permutation_column /* The second set column which in this case is the same as the first set column
                                        */
        );
    }

    /**
     * @brief Get all the entities for the permutation when need to update them
     *
     * @details The entities are returned as a tuple of references in the following order:
     * - The entity/polynomial used to store the product of the inverse values
     * - The entity/polynomial that switches on the subrelation of the permutation relation that ensures correctness of
     * the inverse polynomial
     * - The entity/polynomial that enables adding a tuple-generated value from the first set to the logderivative sum
     * subrelation
     * - The entity/polynomial that enables adding a tuple-generated value from the second set to the logderivative sum
     * subrelation
     * - A sequence of COLUMNS_PER_SET entities/polynomials that represent the first set (N.B. ORDER IS IMPORTANT!)
     * - A sequence of COLUMNS_PER_SET entities/polynomials that represent the second set (N.B. ORDER IS IMPORTANT!)
     *
     * @return All the entities needed for the permutation
     */
    template <typename AllEntities> static inline auto get_nonconst_entities(AllEntities& in)
    {
        return std::forward_as_tuple(
            in.single_permutation_inverses,      /* The polynomial containing the inverse product*/
            in.enable_single_column_permutation, /* The polynomial enabling the product check subrelation */
            in.enable_first_set_permutation,     /* Enables adding first set to the sum */
            in.enable_second_set_permutation,    /* Enables adding second set to the sum */
            in.self_permutation_column,          /* The first set column */
            in.self_permutation_column /* The second set column which in this case is the same as the first set column
                                        */
        );
    }
};

/**
 * @brief This class contains an example of how to set LookupSettings classes used by the
 * GenericLookupRelationImpl class to specify a concrete permutation
 *
 * @details To create your own lookup:
 * 1) Create a copy of this class and rename it
 * 2) Update all the values with the ones needed for your permutation
 * 3) Update "DECLARE_LOOKUP_IMPLEMENTATIONS_FOR_ALL_SETTINGS" and "DEFINE_LOOKUP_IMPLEMENTATIONS_FOR_ALL_SETTINGS" to
 * include the new settings
 * 4) Add the relation with the chosen settings to Relations in the flavor (for example,"`
 *   using Relations = std::tuple<sumcheck::GenericLookupRelation<sumcheck::ExampleLookupBasedRangeConstraintSettings,
 * FF>>;)`
 *
 */
class ExampleLookupBasedRangeConstraintSettings {
  public:
    /**
     * @brief The type of the READ_TERM (lookup operation) that we are using
     *
     * @details 0 stands for basic tuple lookup, where we simply lookup a tuple of values from given entities
     * 1 stands for scaled tuple lookup, which uses a tuple of (current_accumulator - previous_accumulator * shift)
     * values
     * 2 means arbitrary expression that requires the settings to have a specific method and set the READ_TERM_DEGREE to
     * the degree of the expression
     *
     */
    static constexpr size_t READ_TERM_TYPE = 0;
    /**
     * @brief The type of the WRITE_TERM (lookup table entry addition) that we are using
     *
     * @details 0 stands for basic tuple lookup, where we simply lookup a tuple of values from given entities
     * 1 means an arbitrary expression, evaluated through a method defines in these settings. In this case
     * WRITE_TERM_DEGREE has to be set to the degree of the expression
     *
     */
    static constexpr size_t WRITE_TERM_TYPE = 0;

    /**
     * @brief The number of read terms (how many lookups we perform) in each row
     *
     */
    static constexpr size_t READ_TERMS = 1;
    /**
     * @brief The number of write terms (how many additions to the lookup table we make) in each row
     *
     */
    static constexpr size_t WRITE_TERMS = 1;

    /**
     * @brief How many values represent a single lookup object. This value is used by the automatic read term
     * implementation in the relation in case the lookup is a basic or scaled tuple and in the write term if it's a
     * basic tuple
     *
     */
    static constexpr size_t LOOKUP_TUPLE_SIZE = 1;

    /**
     * @brief The polynomial degree of the relation telling us if the inverse polynomial value needs to be computed
     *
     */
    static constexpr size_t INVERSE_EXISTS_POLYNOMIAL_DEGREE = 2;

    /**
     * @brief The degree of the read term if implemented arbitrarily. This value is not used by basic and scaled read
     * terms, but will cause compilation error if not defined
     *
     */
    static constexpr size_t READ_TERM_DEGREE = 0;

    /**
     * @brief The degree of the write term if implemented arbitrarily. This value is not used by the basic write
     * term, but will cause compilation error if not defined
     *
     */

    static constexpr size_t WRITE_TERM_DEGREE = 0;

    /**
     * @brief If this method returns true on a row of values, then the inverse polynomial exists at this index.
     * Otherwise the value needs to be set to zero.
     *
     * @details If this is true then the lookup takes place in this row
     *
     */
    template <typename AllEntities> static inline bool inverse_polynomial_is_computed_at_row(const AllEntities& in)
    {
        return (in.lookup_is_range_constrained == 1) || (in.lookup_is_table_entry == 1);
    }

    /**
     * @brief Subprocedure for computing the value deciding if the inverse polynomial value needs to be checked in this
     * row
     *
     * @tparam Accumulator Type specified by the lookup relation
     * @tparam AllEntities Values/Univariates of all entities row
     * @param in Value/Univariate of all entities at row/edge
     * @return Accumulator
     */
    template <typename Accumulator, typename AllEntities>
    static Accumulator compute_inverse_exists(const AllEntities& in)
    {

        using View = Accumulator::View;
        const auto is_constrained = View(in.lookup_is_range_constrained);
        const auto is_table_entry = View(in.lookup_is_table_entry);
        return (is_constrained + is_table_entry - is_constrained * is_table_entry);
    }

    /**
     * @brief Get all the entities for the lookup when need to update them
     *
     * @details The generic structure of this tuple is described in ./generic_lookup_relation.hpp . The following is
     description for the current case:

     The entities are returned as a tuple of references in the following order (this is for ):
     * - The entity/polynomial used to store the product of the inverse values
     * - The entity/polynomial that specifies how many times the lookup table entry at this row has been looked up
     * - The entity/polynomial that enables the lookup operation at this row
     * - The entity/polynomial that enables adding an entry to the lookup table in this row
     * - The entity/polynomial a value from which is being looked up (since there is one entry, it simply checks if it's
     contained in the set)
     * - The entity/polynomial a value from which is being added to the table
     *
     * @return All the entities needed for the lookup
     */
    template <typename AllEntities> static inline auto get_const_entities(const AllEntities& in)
    {

        return std::forward_as_tuple(
            in.lookup_range_constraint_inverses,   /* The polynomial containing the inverse product*/
            in.lookup_range_constraint_read_count, /* The polynomial enabling the product check subrelation */
            in.lookup_is_range_constrained,        /* Enables adding first set to the sum */
            in.lookup_is_table_entry,              /* Enables adding second set to the sum */
            in.range_constrained_column,           /* The first set column */
            in.lookup_range_table_entries);
    }
    /**
     * @brief Get all the entities for the lookup when only need to read them
     * @details Same as in get_const_entities, but nonconst
     *
     * @tparam AllEntities
     * @param in
     * @return auto
     */
    template <typename AllEntities> static inline auto get_nonconst_entities(AllEntities& in)
    {

        return std::forward_as_tuple(
            in.lookup_range_constraint_inverses,   /* The polynomial containing the inverse product*/
            in.lookup_range_constraint_read_count, /* The polynomial enabling the product check subrelation */
            in.lookup_is_range_constrained,        /* Enables adding first set to the sum */
            in.lookup_is_table_entry,              /* Enables adding second set to the sum */
            in.range_constrained_column,           /* The first set column */
            in.lookup_range_table_entries);
    }
};

#define DEFINE_IMPLEMENTATIONS_FOR_SETTINGS(RelationImplementation, flavor, Settings)                                  \
    template class RelationImplementation<Settings, flavor::FF>;                                                       \
    template <typename FF_> using RelationImplementation##Settings = RelationImplementation<Settings, FF_>;            \
    DEFINE_SUMCHECK_RELATION_CLASS(RelationImplementation##Settings, flavor);

#define DECLARE_IMPLEMENTATIONS_FOR_SETTINGS(RelationImplementation, flavor, Settings)                                 \
    extern template class RelationImplementation<Settings, flavor::FF>;                                                \
    template <typename FF_> using RelationImplementation##Settings = RelationImplementation<Settings, FF_>;            \
    DECLARE_SUMCHECK_RELATION_CLASS(RelationImplementation##Settings, flavor);

#define DEFINE_PERMUTATION_IMPLEMENTATIONS_FOR_ALL_SETTINGS(RelationImplementation, flavor)                            \
    DEFINE_IMPLEMENTATIONS_FOR_SETTINGS(RelationImplementation, flavor, ExampleTuplePermutationSettings);              \
    DEFINE_IMPLEMENTATIONS_FOR_SETTINGS(RelationImplementation, flavor, ExampleSameWirePermutationSettings);

#define DECLARE_PERMUTATION_IMPLEMENTATIONS_FOR_ALL_SETTINGS(RelationImplementation, flavor)                           \
    DECLARE_IMPLEMENTATIONS_FOR_SETTINGS(RelationImplementation, flavor, ExampleTuplePermutationSettings);             \
    DECLARE_IMPLEMENTATIONS_FOR_SETTINGS(RelationImplementation, flavor, ExampleSameWirePermutationSettings);

#define DEFINE_LOOKUP_IMPLEMENTATIONS_FOR_ALL_SETTINGS(RelationImplementation, flavor)                                 \
    DEFINE_IMPLEMENTATIONS_FOR_SETTINGS(RelationImplementation, flavor, ExampleLookupBasedRangeConstraintSettings);

#define DECLARE_LOOKUP_IMPLEMENTATIONS_FOR_ALL_SETTINGS(RelationImplementation, flavor)                                \
    DECLARE_IMPLEMENTATIONS_FOR_SETTINGS(RelationImplementation, flavor, ExampleLookupBasedRangeConstraintSettings);

} // namespace proof_system::honk::sumcheck