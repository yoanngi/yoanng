" **************************************************************************** "
"                                                                              "
"                                                         :::      ::::::::    "
"    .vimrc                                             :+:      :+:    :+:    "
"                                                     +:+ +:+         +:+      "
"    By: yoginet <marvin@42.fr>                     +#+  +:+       +#+         "
"                                                 +#+#+#+#+#+   +#+            "
"    Created: 2017/11/18 10:19:29 by yoginet           #+#    #+#              "
"    Updated: 2017/11/24 11:21:02 by yoginet     ###    #+. /#+    ###.fr      "
"                                                                              "
" **************************************************************************** "

" Activation de la souris
set mouse=a

" nombres de lignes
set number

" Coloration
syntax on

" Indentation intelligente
set smartindent

" Conserve l’indentation sur une nouvelle ligne
set autoindent

" Parametres indentation
set tabstop=4
set shiftwidth=4
set softtabstop=4

" Affiche la position du curseur
set ruler

" Ferme la parenthese, accolade, crochet automatiquement et place le curseur au milieu
"inoremap ( ()<left>
"inoremap { {}<left>
"inoremap [ []<left>

" deux espaces sont Highlighte && whitespace fin de ligne
highlight ExtraWhitespace ctermbg=red guibg=redi
match ExtraWhitespace /\%>11l \{2,}\|\s\+$/


" Fichier tmp
set undodir=~/.vim/.undo//
set backupdir=~/.vim/.backup//
set directory=~/.vim/.swp//
