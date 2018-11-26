/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:10:07 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/23 14:12:32 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_ERRORS_H
# define ASM_ERRORS_H

# define OC_FILE_ERR 70
# define NAME_ERR 71

# define FILE_ERR 72

# define SYNTAX_LABEL 73
# define SYNTAX_ENDLINE 74
# define SYNTAX_END 75
# define SYNTAX_INSTRUCT 76
# define SYNTAX_DIRECT 77
# define SYNTAX_DIRECT_LABEL 78
# define SYNTAX_INDIRECT 79
# define SYNTAX_REGISTER 80
# define SYNTAX_COMMAND_COMMENT 81
# define SYNTAX_COMMAND_NAME 82
# define SYNTAX_SEPARATOR 83
# define NO_NEW_LINE 84

# define INVALID_INSTRUCT 85
# define INVALID_PARAM_FOR_INSTRUCT 86

# define LEXICAL 87

# define DIRECT_LABEL 88

# define WRONG_PARAM_NUM 89

# define TOO_LONG_NAME 90
# define TOO_LONG_COMMENT 91

# define NO_NAME 92
# define NO_COMMENT 93

#endif
