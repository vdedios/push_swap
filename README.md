# Push Swap

Design an algorithm to sort a stack of numbers in the least amount of instructions.

![demo](push_swap_demo.gif)

## Project specifications

You must sort a stack of numbers using only two stacks: A, the main one and B, an auxiliar one. You must do it appliying a limited set of actions:

- `push`: push an element from one stack to the other.
- `swap`: swap the first two elements at the top of the stack.
- `rotate`: place the first element of the stack in the last position.
- `rotate reverse`: place the last element of the stack in the first position.
- `rotate reverse`: place the last element of the stack in the first position.

## Usage

### push_swap

```bash
./push_swap <set_of_numbers>
```

### checker

```bash
./checker [-v:<frame_delay>] [-p:<frame_delay>] [-c]
```

#### Options

    -h: help.
    -v: visualize operations.
    -p: print stacks after exexuting instructions
    -c: print number of push_swap instruction

    [-v] and [-p] cannot coexist

**Note :** `push_swap` program is the responsable of calculating all the necessary instructions while `checker` is responsable of checking if output instructions are ok. This means, stack A get sorted after aplying them and stack B is empty. You must pipe one into another like:

```bash
    ./push_swap <set_of_numbers> | ./checker <set_of_numbers>
```

A simple script, `test.sh` is provided in order to make easy testing with large sets of random numbers:

```bash
    ./test.sh <size_of_set> [<checker-options>]
```

`shuf` utility must be installed:

- **macOS :** `brew install coreutils`
- **linux :** `apt-get install coreutils`



## Contributors
<table>
    <tr>
        <td>
          <img src="https://cdn.intra.42.fr/users/small_vde-dios.jpg" width=140px>
          </br>
          <a href="https://github.com/vdedios">@vdedios</a>
        </td>
    </tr>
</table>

## Support

If you find any issue we suggest that you open a PR with the fix 🙂
