;VESA VBE/AI 1.0 Standard x86 REAL MODE;
/*************************************************************************
 * 
 * Westside Hoboes Systems Incorporated CONFIDENTIAL
 * __________________
 * 
 *  [2015] Westside Hoboes Systems Incorporated
 *  All Rights Reserved.
 * 
 * NOTICE:  All information contained herein is, and remains
 * the property of Westside Hoboes Systems Incorporated and its suppliers,
 * if any.  The intellectual and technical concepts contained
 * herein are proprietary to Westside Hoboes Systems Incorporated
 * and its suppliers and may be covered by U.S. and Foreign Patents,
 * patents in process, and are protected by trade secret or copyright law.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from Westside Hoboes Systems Incorporated.
 */

;This will ultimately serve as a necessary code injection.
;A port of this to pure AMD64 ASM is to be expected in the near future.
;Westside Hoboes Systems Incorporated will likely need to rewrite the specification as well.

;ENTRY POINT;

*VBE RETURN STATUS*
*AL == 4Fh* ;Function is supported
*AL != 4Fh* ;Function is not supported
*AH == 00h* ;Function call successful
*AH == 01h* ;Function call failed
*AH == 02h* ;Function is not supported in the current hardware configuration
*AH == 03h* ;Function call invalid in current video mode

;Assuming the CPU is operating on a fresh stack in REAL MODE;
mov AX, B101h ;BIOS PCI 2.0 installation check
int 1Ah
