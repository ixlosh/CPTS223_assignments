#include "DisjointSets.h"

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */
DisjointSets::DisjointSets( int numElements ) : s( numElements, -1 )
{
}

/**
 * Union two disjoint sets.
 */
void DisjointSets::unionSets( int root1, int root2 )
{
    // TODO
}


/**
 * Perform a find (does not change anything).
 * Return the set containing x.
 */
int DisjointSets::find( int x ) const
{
    // TODO
    return s[0];
}


/**
 * Perform a find with path compression (the mutator version).
 * Return the set containing x.
 */
int DisjointSets::find( int x )
{
    // TODO
    return s[0];
}
