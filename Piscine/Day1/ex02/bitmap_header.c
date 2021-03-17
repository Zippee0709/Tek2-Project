/*
** EPITECH PROJECT, 2020
** bitmap header
** File description:
** bitmap header
*/

#include <stddef.h>
#include "bitmap.h"

void make_bmp_header(bmp_header_t *header, size_t size)
{
    header->magic = 0x424D;
    header->size = 0;
    header->_app1 = 0;
    header->_app2 = 0;
    header->offset = size * size;
}

void make_bmp_info_header(bmp_info_header_t *header, size_t size)
{
    header->size = 40;
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->raw_data_size = size * size * 2;
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}