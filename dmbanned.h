
// Copyright (c) 2018 brinkqiang
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __DMBANNED_H__
#define __DMBANNED_H__

/*
 * MOD BY GIT
 * This header lists functions that have been banned from our code base,
 * because they're too easy to misuse (and even if used correctly,
 * complicate audits). Including this header turns them into compile-time
 * errors.
 */

#define DMBANNED(func) sorry_##func##_is_a_banned_function

#undef strcpy
#define strcpy(x,y) DMBANNED(strcpy)
#undef strcat
#define strcat(x,y) DMBANNED(strcat)
#undef strncpy
#define strncpy(x,y,n) DMBANNED(strncpy)
#undef strncat
#define strncat(x,y,n) DMBANNED(strncat)

#undef sprintf
#undef vsprintf
#ifdef HAVE_VARIADIC_MACROS
#define sprintf(...) DMBANNED(sprintf)
#define vsprintf(...) DMBANNED(vsprintf)
#else
#define sprintf(buf,fmt,arg) DMBANNED(sprintf)
#define vsprintf(buf,fmt,arg) DMBANNED(sprintf)
#endif

#endif /* __DMBANNED_H__ */
