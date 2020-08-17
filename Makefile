# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 15:26:30 by rchallie          #+#    #+#              #
#    Updated: 2020/08/17 19:07:16 by rchallie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM INFORMATIONS =========================================================
NAME = ft_nm-otool
NAME_NM	= ft_nm
# ==============================================================================

# COLORS =======================================================================
GREEN=$'\x1b[32m
WHITE=$'\x1b[37m
# ==============================================================================

# SOURCES ======================================================================
SOURCES_DIR_NM = ft_nm_project/sources_nm/
SOURCES_NM = 	ft_nm.c \
				memory_map.c \
				error.c \
				interface.c
SOURCES_NM_PREFIXED = $(addprefix $(SOURCES_DIR_NM), $(SOURCES_NM))
# ==============================================================================

# INCLUDES =====================================================================
INCLUDES_LIBFT = libft/

INCLUDES_NM = ft_nm_project/includes_nm/
# ==============================================================================

# OBJECTS ======================================================================
OBJECTS_DIR_NM = ft_nm_project/objects_nm/
OBJECT_NM = $(SOURCES_NM:.c=.o)
OBJECTS_NM = $(addprefix $(OBJECTS_DIR_NM), $(OBJECT_NM))
# ==============================================================================

# FLAGS ========================================================================
FLAGS = -Wall -Wextra -Werror -std=c99
# ==============================================================================

# OBJECTS COMPILE ==============================================================
$(OBJECTS_DIR_NM)%.o : $(SOURCES_DIR_NM)%.c $(INCLUDES_NM)/ft_nm.h
		@mkdir -p $(OBJECTS_DIR_NM)
		@echo "$(_WHITE)Compiling: $(_GREEN)$<$(_WHITE)"
		@clang $(FLAGS) -c $< -o $@
# ==============================================================================

# LIBRARIES ====================================================================
LIB_LIBFT = $(INCLUDES_LIBFT)libft.a
# ==============================================================================

# COMMONS ======================================================================

$(NAME): $(OBJECTS_NM)
		@$(MAKE) bonus -C libft 
		@echo "Compiling $(NAME_NM) ..."
		@clang $(FLAGS) -I $(INCLUDES_NM) $(OBJECTS_NM) $(LIB_LIBFT) -o $(NAME_NM)
		@echo "$(_GREEN)Done!$(_WHITE)"

all: $(NAME)

clean:
		@$(MAKE) clean -C libft
		@echo "$(_WHITE)Cleaning: $(_GREEN)$(OBJECTS_DIR_NM)$(_WHITE)"
		@rm -rf $(OBJECTS_DIR_NM)

fclean: clean
		@$(MAKE) fclean -C libft 
		@echo "$(_WHITE)Cleaning: $(_GREEN)$(NAME_NM)$(_WHITE)"f
		@rm -f $(NAME_NM)

re: fclean all

# ==============================================================================

# ADDONS =======================================================================
run : all
	./ft_nm .test-program/test-program
# ==============================================================================
