" This config uses junegunn/vim-plug.

" Plugins will be downloaded here.
call plug#begin('~/.vim/plugged')

" List of plugins.
Plug 'ycm-core/YouCompleteMe'
Plug 'itchyny/vim-gitbranch'
Plug 'itchyny/lightline.vim'
Plug 'flazz/vim-colorschemes'
Plug 'airblade/vim-gitgutter'

" List ends here.
call plug#end()

set laststatus=2
set completeopt-=preview
set number
set ruler
set shiftwidth=4
set tabstop=4
set expandtab
set autoindent

set t_Co=256
set t_ut=""
set noshowmode
colo wombat256dave

let g:lightline = {
    \ 'colorscheme': 'wombat',
    \ 'active': {
	\   'left': [[ 'mode', 'paste' ],
    \            [ 'gitbranch', 'readonly', 'filename', 'modified' ]]
	\ },
    \ 'component_function': {
	\   'gitbranch': 'gitbranch#name'
    \ },
    \ }

