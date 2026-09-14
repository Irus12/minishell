// quotes vides
"echo ''"           // output: (vide) [YES]
"echo \"\""         // output: (vide) [YES] (sans le cleanup c juste)
"echo ''hello''"    // output: hello [IDK]
"echo \"\"hello\"\"" // output: hello [YES] (sans le cleanup c juste)

// quotes collées
"echo 'hello''world'"      // output: helloworld [YES]
"echo 'hello'\"world\""    // output: helloworld [YES] (sans le cleanup c juste)
"echo \"hello\"'world'"    // output: helloworld [YES] (sans le cleanup c juste)

// quotes avec espaces
"echo 'hello world'"       // output: hello world   (1 argument) [YES]
"echo \"hello world\""     // output: hello world   (1 argument) [YES]
"echo 'hello   world'"     // output: hello   world (espaces conservés) [YES]

// quotes avec variables (export USER=alice) 
"echo \"$USER\""           // output: alice [IDK] needs cleanup
"echo '$USER'"             // output: $USER [YES]
"echo \"$USER\"'$USER'"    // output: alice$USER [IDK] needs cleanup

// quotes avec caractères spéciaux
"echo 'hello | world'"     // output: hello | world  (pas un pipe) [YES]
"echo 'hello > world'"     // output: hello > world  (pas une redirection) [YES]
"echo 'hello < world'"     // output: hello < world [YES]
"echo 'hello >> world'"    // output: hello >> world [YES]

// quotes avec $
"echo '$'"                 // output: $ [YES]
"echo \"$\""               // output: $ [YES]
"echo \"$?\""              // output: 0  (ou dernier exit status) [YES]
"echo '$?'"                // output: $? [NEED_MORE_TESTS]

// commande entre quotes
"'echo' salut"             // output: salut  (les quotes sont enlevées sur la commande) 

// quotes pas fermées
"echo 'hello"              // output: erreur syntax ou bash continue sur ligne suivante
"echo \"hello"             // output: erreur syntax ou bash continue sur ligne suivante

// cas tordus
"echo 'it'\\''s me'"      // output: it's me [IA_RACONTE_DE_LA_D]
"echo ''$USER''"           // output: alice  (quotes vides autour d'une variable)
"echo \"$USER is\" 'cool'" // output: alice is cool


/////////////////////////////////////////////////////////////////////////////////////////

cat << ''eof'c
est stocke comme : delimiter=eof expandable=0


Heredoc
y'a des cas ou le heredoc ne veut pas se fermer 
et on dirait que la seul condition pour que ca expand pas c'est qu'il
faut minimum 1 paire de single quote dans la string


c2r8s8% cat << oef
heredoc> ds
heredoc> oef
ds
c2r8s8% cat << 'ef''et'
heredoc> $USER
heredoc> 'ef''et'
heredoc> 'ef''et'  
heredoc> 'effet'   
heredoc> efet      
$USER
'ef''et'
'ef''et'
'effet'
c2r8s8% cat << 'tes't  
heredoc> $USER
heredoc> test
$USER
c2r8s8% bash         
nschilli@c2r8s8:~/group_proj/minishell$ cat << 'ef''et'
> $USER
> efet
$USER
nschilli@c2r8s8:~/group_proj/minishell$ cat << ''eof
> $USER
> eof
$USER
nschilli@c2r8s8:~/group_proj/minishell$ cat << 'eof
> $USER
> eof
> 'eof
> eof
> '
> 'eof'
> ^C
nschilli@c2r8s8:~/group_proj/minishell$ cat << 'e'f'
> $USER
> ef
> e'f
> 'e'f'
> 'ef'
> ^C
nschilli@c2r8s8:~/group_proj/minishell$ 


/////////////////////////////////////
./minishell
minishell> echo $USER
nico
minishell> echo $USER
nico
minishell> 
minishell> 
minishell> 
minishell> export a=ckampicfmawpiwam
minishell> echo $a
ckampicfmawpiwam
minishell> echo $a
ckampicfmawpiwam
minishell> export b=ls
minishell> echo $b
ls
minishell> $b
Command not found: ls
minishell> $b
Command not found: ls
minishell> export c="ls -a"
minishell> $c
Command not found: ls -a
minishell> export c
minishell> $c
Command not found: ls -a
minishell> echo $usus

minishell> echo $usus

minishell> env
minishell> 
minishell> ls
Command not found: ls
minishell> env
minishell> export
minishell> 

/////////////

 ./minishell
minishell> export a=ls
minishell> a
Command not found: a
minishell> $a
Command not found: ls
minishell> env
a=ls
minishell> ls
Command not found: ls
minishell> env
a=ls
minishell> cd
cd: HOME not set
minishell> ls
Command not found: ls
minishell> 
exit

////////
 ./minishell
minishell> export a=ls
minishell> ls
Makefile  README.md  builtins  edgecases.md  libft  libft_merged  main_init  minishell  minishell.h  obj  parsing  src  t_exec  test_parser  utils
minishell> $a
Command not found: ls
minishell> ls
Command not found: ls
minishell> env
a=ls
minishell> 


////////

./minishell
minishell> ls
Makefile  README.md  builtins  edgecases.md  libft  libft_merged  main_init  minishell  minishell.h  obj  parsing  src  t_exec  test_parser  utils
minishell> env
CODE_INJECTION=1
TERM_PROGRAM=vscode
VSCODE_PYTHON_AUTOACTIVATE_GUARD=1
*le reste de var sont là j'affiche pas tout*
DISPLAY=:0
USER=nico
TERM_PROGRAM_VERSION=1.135.0
SHLVL=3
minishell> export d=hello
minishell> env
d=hello
minishell> 
exit