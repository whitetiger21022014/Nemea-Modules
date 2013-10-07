/**
 * \file entropy.h
 * \brief Common functions and macros for entropy module
 * \author Tomas Cejka <cejkat@cesnet.cz>
 * \date 2013
 */
/*
 * Copyright (C) 2013 CESNET
 *
 * LICENSE TERMS
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of the Company nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * ALTERNATIVELY, provided that this notice is retained in full, this
 * product may be distributed under the terms of the GNU General Public
 * License (GPL) version 2 or later, in which case the provisions
 * of the GPL apply INSTEAD OF those given above.
 *
 * This software is provided ``as is'', and any express or implied
 * warranties, including, but not limited to, the implied warranties of
 * merchantability and fitness for a particular purpose are disclaimed.
 * In no event shall the company or contributors be liable for any
 * direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute
 * goods or services; loss of use, data, or profits; or business
 * interruption) however caused and on any theory of liability, whether
 * in contract, strict liability, or tort (including negligence or
 * otherwise) arising in any way out of the use of this software, even
 * if advised of the possibility of such damage.
 *
 */
#ifndef _ENTROPY_H
#define _ENTROPY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * \defgroup entropy
 * @{
 */
/**
 * \defgroup byteentropy Byte based entropy computation
 * @{
 */
void ent_reset(uint32_t **ent_data);

double ent_get_entropy(uint32_t *ent_data);

void ent_put_data(uint32_t *ent_data, char *data, uint32_t data_size);

void ent_free(uint32_t **ent_data);
/**
 * @}
 */

/**
 * \defgroup cuckootableentropy Hash table based entropy computation (cuckoo hashing)
 * @{
 */

#define ent_hash_t void

ent_hash_t *ent_hash_init(unsigned int table_size, unsigned int key_length);

void ent_hash_put_data(ent_hash_t *inst, char *data);

void ent_hash_reset(ent_hash_t *inst);

double ent_hash_get_entropy(ent_hash_t *inst);

void ent_hash_free(ent_hash_t **inst);

/**
 * @}
 */

/**
 * \defgroup superhashtableentropy Hash table based entropy computation
 * @{
 */

#define ent_shash_t void

ent_shash_t *ent_shash_init(unsigned int table_size, unsigned int key_length);

void ent_shash_put_data(ent_shash_t *inst, char *data);

void ent_shash_reset(ent_shash_t *inst);

double ent_shash_get_entropy(ent_shash_t *inst);

void ent_shash_free(ent_shash_t **inst);

/**
 * @}
 */

/**
* @}
*/

#endif


