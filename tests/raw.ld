OUTPUT_FORMAT( "binary" )
ENTRY(_start)

SECTIONS
{
    . = 0x0;            /* Set starting address to 0x0 */
    .data : {
        *(.data) 
    }
    . = 0x8000;
    .text : {
        *(.text)        /* Place all code from the .text section here */
    }
    /DISCARD/ : {       /* Discard all other sections (like .data, .bss, etc.) */
        *(.bss)
        *(.comment)
        *(.note.GNU-stack)
    }
}