.. _id:

******************
Pastry identifiers
******************

.. highlight:: c

::

  #include <croissant.h>

The types and functions in this section can be used to interact with
160-bit Pastry node identifiers.

.. type:: struct crs_id

   A Pastry node identifier.  Internally, the identifier is always
   stored in big-endian order.

   .. member:: uint8_t _.u8[20]

      The individual bytes of the identifier.

   .. member:: uint32_t _.u32[5]

      32-bit chunks of the identifier.

.. macro:: CRS_ID_BIT_LENGTH
           CRS_ID_NYBBLE_LENGTH

   The number of bits and nybbles in a Pastry node identifier.

.. function:: bool crs_id_init(struct crs_id \*id, const char \*src)

   Initialize a Pastry identifier from a string.  Returns whether the
   string contained a valid identifier.

.. function:: void crs_id_copy(struct crs_id \*dest, const struct crs_id \*src)

   Copy a Pastry identifier from *src* to *dest*.

.. function:: bool crs_id_equals(const struct crs_id \*id1, const struct crs_d \*id2)

   Returns whether two Pastry identifiers are equal.

.. function:: unsigned int crs_id_get_nybble(const struct crs_id \*id, unsigned int index)

   Returns the given nybble of an identifier.

.. function:: int crs_id_get_msdd(const struct crs_id \*id1, const struct crs_id \*id2)

   Returns the most-significant different digit (MSDD) between two
   identifiers.  If the two identifiers are identical, returns ``-1``.

.. macro:: CRS_ID_STRING_LENGTH

   The maximum length of the string representation of a Pastry node
   identifier, including a ``NUL`` terminator.

.. function:: void crs_id_to_raw_string(const struct crs_id \*id, char \*dest)

   Fills in *dest* with the string representation of a Pastry
   identifier.  You are responsible for ensuring that *dest* is large
   enough to hold the string representation of any valid identifier.
   The :c:macro:`CRS_ID_STRING_LENGTH` macro can be helpful for this::

     char  buf[CRS_ID_STRING_LENGTH];
     struct crs_id  id;
     crs_id_to_raw_string(&id, buf);
