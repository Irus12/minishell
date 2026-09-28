*This project has been created as part of the 42 curriculum by nschilli, romousqu.*
# Minishell

## Description

Minishell is a small interactive command-line shell written in C as a 42 school project. Its goal is to recreate a focused subset of the behavior of a Unix shell: read a command line, tokenize and parse it, expand supported variables, then execute builtins or external programs.

The shell supports quoted words, environment-variable and exit-status expansion, pipelines, input/output redirections, and heredocs. It uses GNU Readline for the interactive prompt and command history. This is an educational shell rather than a complete POSIX or Bash implementation; behavior outside the supported features may differ from standard shells.

### Features

- Interactive prompt with Readline history.
- Builtins: `echo`, `cd`, `pwd`, `env`, `export`, `unset`, and `exit`.
- Execution of external programs, including lookup through `PATH`.
- Single- and double-quoted words, with environment-variable expansion and `$?` for the last exit status.
- Pipelines (`|`), input redirection (`<`), output redirection (`>` and `>>`), and heredocs (`<<`).
- Basic signal handling for the interactive prompt and child processes.

## Instructions

### Compilation

to compile the project, simply do:
```sh
make
./minishell
```

Example commands:

```sh
minishell > echo "hello $USER"
minishell > export GREETING=hello
minishell > echo "$GREETING" | cat
minishell > cat < input.txt >> output.txt
minishell > cat << EOF
text from the heredoc
EOF
```

Enter `exit` or press Ctrl-D to leave the shell. The available syntax is intentionally limited and should not be assumed to match Bash in every case.

## Project layout

- `main_init/` — shell initialization and input loop.
- `parsing/` — lexer, parser, quote handling, and expansion.
- `t_exec/` — command execution, pipes, redirections, and heredocs.
- `builtins/` — shell builtin implementations.
- `utils/` — shared helpers, cleanup, status, and signal utilities.
- `libft_merged/` — bundled libft and related support functions.

## Resources

Minishell guide - https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218
Minishell guide -https://github.com/mcombeau/minishell
GNU Bash Reference Manual - https://www.gnu.org/software/bash/manual/bash.html
GNU Readline documentation - https://tiswww.case.edu/php/chet/readline/readline.html
POSIX Shell Command Language - https://pubs.opengroup.org/onlinepubs/9799919799/utilities/V3_chap02.html
 Linux manual pages: `execve(2)`, `pipe(2)`, `dup2(2)`, `waitpid(2)`, `signal(7)`

### AI usage

For this documentation task, AI was used to inspect the repository and help summarize its implemented features, build steps, project layout, and relevant references in this README. No source code was generated or changed by AI as part of this README-writing task. This statement describes the assistance for this documentation task; update it if AI was also used for other parts of the project.
