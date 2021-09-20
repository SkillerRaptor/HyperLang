/*
 * Copyright (c) 2020-2021, SkillerRaptor <skillerraptor@protonmail.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "logger.h"

#include "colors.h"

#include <stdarg.h>
#include <stdio.h>

#if defined(__clang__)
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wformat-nonliteral"
#endif

void print(const char* str, ...)
{
	printf(FORMAT_RESET);
	
	va_list args;
	va_start(args, str);
	vprintf(str, args);
	va_end(args);
}

void hyper_fatal_error(const char* str, ...)
{
	printf(FORMAT_BOLD COLOR_WHITE "hyper: " COLOR_RED "fatal error: " FORMAT_RESET);
	
	va_list args;
	va_start(args, str);
	vprintf(str, args);
	va_end(args);
}

#if defined(__clang__)
#   pragma clang diagnostic pop
#endif
