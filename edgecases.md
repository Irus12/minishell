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