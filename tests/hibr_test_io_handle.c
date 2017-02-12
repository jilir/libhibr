/*
 * Library io_handle type test program
 *
 * Copyright (C) 2012-2017, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "hibr_test_libcerror.h"
#include "hibr_test_libhibr.h"
#include "hibr_test_macros.h"
#include "hibr_test_memory.h"
#include "hibr_test_unused.h"

#include "../libhibr/libhibr_io_handle.h"

#if defined( __GNUC__ )

/* Tests the libhibr_io_handle_initialize function
 * Returns 1 if successful or 0 if not
 */
int hibr_test_io_handle_initialize(
     void )
{
	libcerror_error_t *error        = NULL;
	libhibr_io_handle_t *io_handle  = NULL;
	int result                      = 0;

#if defined( HAVE_HIBR_TEST_MEMORY )
	int number_of_malloc_fail_tests = 1;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libhibr_io_handle_initialize(
	          &io_handle,
	          &error );

	HIBR_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        HIBR_TEST_ASSERT_IS_NOT_NULL(
         "io_handle",
         io_handle );

        HIBR_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libhibr_io_handle_free(
	          &io_handle,
	          &error );

	HIBR_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        HIBR_TEST_ASSERT_IS_NULL(
         "io_handle",
         io_handle );

        HIBR_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libhibr_io_handle_initialize(
	          NULL,
	          &error );

	HIBR_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        HIBR_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	io_handle = (libhibr_io_handle_t *) 0x12345678UL;

	result = libhibr_io_handle_initialize(
	          &io_handle,
	          &error );

	HIBR_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        HIBR_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	io_handle = NULL;

#if defined( HAVE_HIBR_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libhibr_io_handle_initialize with malloc failing
		 */
		hibr_test_malloc_attempts_before_fail = test_number;

		result = libhibr_io_handle_initialize(
		          &io_handle,
		          &error );

		if( hibr_test_malloc_attempts_before_fail != -1 )
		{
			hibr_test_malloc_attempts_before_fail = -1;

			if( io_handle != NULL )
			{
				libhibr_io_handle_free(
				 &io_handle,
				 NULL );
			}
		}
		else
		{
			HIBR_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			HIBR_TEST_ASSERT_IS_NULL(
			 "io_handle",
			 io_handle );

			HIBR_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libhibr_io_handle_initialize with memset failing
		 */
		hibr_test_memset_attempts_before_fail = test_number;

		result = libhibr_io_handle_initialize(
		          &io_handle,
		          &error );

		if( hibr_test_memset_attempts_before_fail != -1 )
		{
			hibr_test_memset_attempts_before_fail = -1;

			if( io_handle != NULL )
			{
				libhibr_io_handle_free(
				 &io_handle,
				 NULL );
			}
		}
		else
		{
			HIBR_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			HIBR_TEST_ASSERT_IS_NULL(
			 "io_handle",
			 io_handle );

			HIBR_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_HIBR_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( io_handle != NULL )
	{
		libhibr_io_handle_free(
		 &io_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the libhibr_io_handle_free function
 * Returns 1 if successful or 0 if not
 */
int hibr_test_io_handle_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libhibr_io_handle_free(
	          NULL,
	          &error );

	HIBR_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        HIBR_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc HIBR_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] HIBR_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc HIBR_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] HIBR_TEST_ATTRIBUTE_UNUSED )
#endif
{
	HIBR_TEST_UNREFERENCED_PARAMETER( argc )
	HIBR_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ )

	HIBR_TEST_RUN(
	 "libhibr_io_handle_initialize",
	 hibr_test_io_handle_initialize );

	HIBR_TEST_RUN(
	 "libhibr_io_handle_free",
	 hibr_test_io_handle_free );

	/* TODO: add tests for libhibr_io_handle_clear */

	/* TODO: add tests for libhibr_io_handle_read_memory_image_information */

	/* TODO: add tests for libhibr_io_handle_read_compressed_page_data */

#endif /* defined( __GNUC__ ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
