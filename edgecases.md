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