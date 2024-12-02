/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfischof <pfischof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:51:43 by pfischof          #+#    #+#             */
/*   Updated: 2024/12/01 22:10:24 by pfischof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* -------------------------------------------------------------------------- */
/*                                   HEADERS                                  */
/* -------------------------------------------------------------------------- */

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>

/* -------------------------------------------------------------------------- */
/*                                   MACROS                                   */
/* -------------------------------------------------------------------------- */

# define SUCCESS		0

# define ERROR				-1
# define CONVERSION_LEN		2
# define ALT_LEN			2
# define NUMBER_OF_FLAGS	7
# define BASE_10			10
# define BASE_16			16

# define FORMAT			"%cspdiuxX"
# define NUMERICALS		"diuxX"
# define HEX			"xX"
# define OPT			"# +-0"
# define NULL_FORMAT	"NULL"
# define DECIMAL		"0123456789"
# define HEX_LOWER		"0123456789abcdef"
# define HEX_UPPER		"0123456789ABCDEF"
# define ALT_LOWER		"0x"
# define ALT_UPPER		"0X"
# define BLANK			" "
# define MINUS_SIGN		"-"
# define PLUS_SIGN		"+"
# define NULL_STR		"(null)"

# define FORMAT_PERCENT		'%'
# define FORMAT_CHARACTER	'c'
# define FORMAT_STRING		's'
# define FORMAT_POINTER		'p'
# define FORMAT_DECIMAL		'd'
# define FORMAT_INTEGER		'i'
# define FORMAT_UINTEGER	'u'
# define FORMAT_HEXA_LOWER	'x'
# define FORMAT_HEXA_UPPER	'X'

# define OPT_SIGNED			'+'
# define OPT_ALT_FORM		'#'
# define OPT_LEFT_ADJUST	'-'
# define OPT_SPACE			' '
# define OPT_ZERO_PADDING	'0'
# define OPT_PRECISION		'.'

# define NULL_CHAR	'\0'
# define ZERO_CHAR	'0'
# define NINE_CHAR	'9'
# define MINUS_CHAR	'-'
# define SPACE_CHAR	' '

# ifdef __linux__
#  define OS_NULL_PTR	"(nil)"
# endif
# ifdef __APPLE__
#  define OS_NULL_PTR	"0x0"
# endif

/* -------------------------------------------------------------------------- */
/*                                    ENUMS                                   */
/* -------------------------------------------------------------------------- */

typedef enum e_flags
{
	ALTERNATE_FORM,
	FORCED_SPACE,
	LEFT_ADJUSTING,
	PRECISION,
	SIGN,
	WIDTH,
	ZERO_PADDING,
}	t_flags;

typedef enum e_width
{
	HEXADECIMAL,
	INTEGER,
	POINTER,
	STRING,
	UINTEGER,
}	t_width;

/* -------------------------------------------------------------------------- */
/*                                 STRUCTURES                                 */
/* -------------------------------------------------------------------------- */

typedef struct s_conversion
{
	int		size;
	char	*content;
	bool	signed_number;
}	t_conversion;

typedef struct s_padding
{
	int		size;
	char	*content;
}	t_padding;

typedef struct s_precision
{
	int		size;
	char	*content;
}	t_precision;

typedef struct s_output
{
	int		size;
	char	*content;
}	t_output;

typedef struct s_data
{
	bool			flags[NUMBER_OF_FLAGS];
	char			*alternate;
	char			*blank;
	char			*sign;
	char			format;
	t_conversion	conversion;
	t_padding		padding;
	t_precision		precision;
	t_output		output;
	int				size;
}	t_data;

/* -------------------------------------------------------------------------- */
/*                                 FUNCTIONS                                  */
/* -------------------------------------------------------------------------- */

/* ------------------------------- CONVERSIONS ------------------------------ */

void	convert_field(t_data *data, va_list ap);

void	convert_blank(t_data *data);
void	convert_padding(t_data *data);
void	convert_precision(t_data *data);
void	convert_sign(t_data *data);

void	convert_character(t_data *data, char character);
void	convert_string(t_data *data, char *string);

void	convert_alternate(t_data *data, char *alt);
void	convert_decint(t_data *data, int number);
void	convert_hexadecimal(t_data *data, unsigned int number);
void	convert_pointer(t_data *data, void *pointer);
void	convert_uinteger(t_data *data, unsigned int number);

/* ---------------------------------- DATA ---------------------------------- */

void	clean_data(t_data *data);
void	clean_flags(t_data *data);
void	init_data(t_data *data);
void	join_data(t_data *data);

/* --------------------------------- PARSING -------------------------------- */

int		parse_flag(t_data *data, char character);
int		parse_format(t_data *data, const char *format);
int		parse_padding(t_data *data, char character);
int		parse_precision(t_data *data, char character);

void	process_format(t_data *data, const char *format, va_list ap);

/* --------------------------------- PRINTF --------------------------------- */

int		ft_dprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);
int		ft_snprintf(char *output, size_t size, const char *format, ...);
int		ft_sprintf(char *output, const char *format, ...);

/* ---------------------------------- UTILS --------------------------------- */

char	*ft_itoa_base(unsigned long long number, int base_length);
char	*ft_strchr(const char *string, int character);
char	*ft_strcpy(char *destination, char *source);
char	*ft_strdup(const char *original);
char	*ft_strncpy(char *destination, char *source, size_t size);

int		ft_strlen(const char *string);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

void	ft_free(void **pointer);

void	*ft_memset(void *pointer, int character, size_t length);
void	*ft_valloc(int value, size_t count, size_t size);

/* --------------------------------- VPRINTF -------------------------------- */

int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_vsnprintf(char *output, size_t size, const char *format, va_list ap);
int		ft_vsprintf(char *output, const char *format, va_list ap);

#endif
