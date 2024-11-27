/**
 * @file linear_data_structure.h
 * @brief This file contains the declarations for the linear data structure library.
 */

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>


/**
 * @brief Struct that represents the linear data structure
 * 
 * 
 */
typedef struct 
{
    //** Pointer to the data */
    int *data;

    //** The number of elements the data structure can store currently */
    int capacity;

    //** The number of elements present in the data structure */
    int size;
} lin_ds;

/**
 * @brief Creates and allocates memory for an instance of the linear data structure.
 * 
 * @param initial_capacity The capacity the data structure should have when initializing it.
 * 
 * @return Returns a pointer to the data structure.
 */
lin_ds *create_lin_ds(size_t initial_capacity);


/**
 * @brief Resizes the data structure capacity and reallocates memory for it
 * 
 * @param lds The pointer to the data structure that should be resized
 */
void resize_lin_ds(lin_ds *lds);

/**
 * @brief Returns the size of the data structure.
 * 
 * @param lds The pointer to the data structure.
 * 
 * @return The number of elements in the data structure
 */
int size(lin_ds *lds);


/**
 * @brief Checks if the data structure is empty or not.
 * 
 * @param lds The pointer to the data structure.
 * 
 * @return A boolean representing if its empty (true) or not (false)
 */
bool is_empty(lin_ds *ds);
