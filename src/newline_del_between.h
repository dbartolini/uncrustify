/**
 * @file newline_del_between.h
 * prototypes for newline_del_between.cpp
 *
 * @author  Ben Gardner
 * @author  Guy Maurel
 * extract from newlines.cp
 * @license GPL v2+
 */

#ifndef NEWLINE_DEL_BETWEEN_H_INCLUDED
#define NEWLINE_DEL_BETWEEN_H_INCLUDED

#include "chunk.h"

/**
 * Removes any CT_NEWLINE or CT_NL_CONT between start and end.
 * Start must be before end on the chunk list.
 * If the 'PCF_IN_PREPROC' status differs between two tags, we can't remove
 * the newline.
 *
 * @param start  The starting chunk (if it is a newline, it will be removed!)
 * @param end    The ending chunk (will not be removed, even if it is a newline)
 *
 * @return true/false - removed something
 */
void newline_del_between(Chunk *start, Chunk *end);

#endif /* NEWLINE_DEL_BETWEEN_H_INCLUDED */
