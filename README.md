*This project has been created as part of the 42 curriculum by nschilli, romeo.*

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

- [42 Minishell project subject](https://projects.intra.42.fr/) — consult the subject assigned by your campus for the project requirements.
- [GNU Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html) — useful shell behavior reference; this project implements only a subset.
- [GNU Readline documentation](https://tiswww.case.edu/php/chet/readline/readline.html) — interactive line input and history library documentation.
- [POSIX Shell Command Language](https://pubs.opengroup.org/onlinepubs/9799919799/utilities/V3_chap02.html) — standard reference for shell language concepts.
- Linux manual pages: `execve(2)`, `pipe(2)`, `dup2(2)`, `waitpid(2)`, and `signal(7)` — system-call and process-handling references.
- 42 Minishell subject and peer evaluations — useful for project-specific requirements and edge-case validation.

### AI usage

For this documentation task, AI was used to inspect the repository and help summarize its implemented features, build steps, project layout, and relevant references in this README. No source code was generated or changed by AI as part of this README-writing task. This statement describes the assistance for this documentation task; update it if AI was also used for other parts of the project.
