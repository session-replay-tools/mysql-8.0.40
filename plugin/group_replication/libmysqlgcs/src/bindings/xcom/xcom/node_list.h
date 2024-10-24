/* Copyright (c) 2015, 2024, Oracle and/or its affiliates.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is designed to work with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have either included with
   the program or referenced in the documentation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

#ifndef NODE_LIST_H
#define NODE_LIST_H

#include "xdr_gen/xcom_vp.h"

node_list clone_node_list(node_list list);
void init_node_list(u_int n, node_address *names, node_list *nodes);
int match_node(node_address *n1, node_address *n2, u_int with_uid);
void add_node_list(u_int n, node_address *names, node_list *nodes);
int node_exists(node_address *name, node_list const *nodes);
int node_exists_with_uid(node_address *name, node_list const *nodes);
node_address *new_node_address(u_int n, char *names[]);
node_address *new_node_address_uuid(u_int n, char *names[], blob uuid[]);
void delete_node_address(u_int n, node_address *na);
void remove_node_list(u_int n, node_address *names, node_list *nodes);
node_address *init_single_node_address(node_address *na, char *name);
node_address *init_node_address(node_address *na, u_int n, char *names[]);
node_list *empty_node_list();
blob clone_blob(blob const b);
uint32_t chksum_node_list(node_list const *nodes);

#endif
