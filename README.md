# ft_printf :memo:


**ft_printf ([42cursus](https://www.42.fr)) 2023**

**Actual Status :** Finished

**Result :** 125%

The goal of this project is quite simple — to recode printf() and understand how functions with a variable number of arguments work.

## The main part:

In the first part of the project, I recorded the printf() function from libc.
The prototype of ft_printf() is:

```
int ft_printf(const char *, ...);
```
Here are the project requirements for this part:
- Don’t implement the buffer management of the original `printf()`
- The function should handle the following conversions: `cspdiuxX%`
- The function will be compared with the original `printf()`

### Arguments:
format – a pointer to a string with a description of the format.

### Return value:
Upon successful completion of the output, the number of characters output is returned.
If an error occurs, a negative number is returned.

### Description:
The ft_printf function output to the standard output stream a string formatted according to the rules specified in the string pointed to by the `format` argument.

Rules are defined by a set of three types of directives:
1. Regular characters (except `%` and `\`), which are output unchanged;
2. Format specifiers;
3. Special characters.

### Format Specifiers:

Each format specifier starts with the `%` character and has the following format:

```
%[flags][width][precision][type of conversion]
```

### Type of conversion:

The `[type of conversion]` specifier determines how a number should be interpreted and output, for example, as a signed integer in decimal, or an unsigned integer in hexadecimal, or as a floating-point number, and so on.

<table>
  <tbody>
    <tr>
      <th>type of conversion</th>
      <th>purpose of the conversion</th>
    </tr>
    <tr>
      <td> d,i </td>
      <td>output of a signed integer in decimal notation. By default, a sizeof(int) number is output, with right alignment, indicating the sign only for negative numbers</td>
    </tr>
    <tr>
      <td> u </td>
      <td>output of an unsigned integer in decimal notation. By default, a sizeof(int) number is output, with right alignment</td>
    </tr>
	<tr>
      <td> x,X </td>
      <td>output of an unsigned integer in hexadecimal notation. Moreover, 'abcdef' symbols are used for the conversion of x, and 'ABCDEF' symbols are used for X. By default, a sizeof(int) number is output, with right alignment</td>
    </tr>
	<tr>
      <td> с </td>
      <td>output of the symbol corresponding to the number specified in the function argument. By default, the number is converted to the unsigned char type</td>
    </tr>
	<tr>
      <td> s </td>
      <td>output of the string referenced by the pointer in the argument of the ft_printf function. The string is output until the character end of the string (/0) is encountered. By default, the string should be designated as char*</td>
    </tr>
	<tr>
      <td> p </td>
      <td>pointer output. The input result depends on the architecture and the compiler used. For example, on a 16-bit MS-DOS platform, the output will look like FFAB:1402, and on a 32-bit platform with flat addressing - 00FC0120.</td>
    </tr>
  </tbody>
</table>

### Special characters

<table>
  <tbody>
    <tr>
      <th>character code</th>
      <th>symbol assignment</th>
    </tr>
    <tr>
      <td>\% or %%</td>
      <td>percentage withdrawal</td>
    </tr>
    <tr>
	</tbody>
</table>

## Bonus part:

### Bonus list:
- Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions
- Manage all the following flags: ’# +’ (Yes, one of them is a space)

### What was implemented in this project:

#### Flags: 
The format specifier can have 0 or more `[flags]`

<table>
  <tbody>
    <tr>
      <th>flag</th>
      <th>flag assignment</th>
    </tr>
    <tr>
      <td> - </td>
      <td>the result of the conversion is aligned to the left (by default, to the right)</td>
    </tr>
    <tr>
      <td> + </td>
      <td>a '+' sign is displayed before positive numbers, and a '-' sign is displayed before negative numbers (by default, only the '-' sign is displayed before negative numbers)</td>
    </tr>
	<tr>
      <td> ' ' (space character) </td>
      <td>if the modifier '+' is not specified, then a space will be displayed before positive numbers, in place of the number sign </td>
    </tr>
	<tr>
      <td> # </td>
      <td>Use an alternative form of representation of the output number. When displaying numbers in hexadecimal format (converter 'x' or 'X'), 0x or 0X will be indicated before the number, respectively. When displaying numbers in octal format (converter 'o'), 0 will be indicated before the number.</td>
    </tr>
	<tr>
      <td> 0 </td>
      <td>if the '-' flag is not specified, then the characters '0' will be displayed to the left of the output number to fit the number to the specified width. If precision is specified for the converters d, i, x or X, then the 0 flag is ignored</td>
    </tr>
  </tbody>
</table>

The `[flags]` specifier can be omitted.

#### Width 
The `[width]` specifier specifies the minimum size of the output number in characters. If the number of characters in the output number is less than the specified minimum width, then the missing number of characters is filled with zeros or spaces on the left or right, depending on the specified flags. The width is specified either as an integer or by the character * followed by the name of an int variable containing the width value before the argument to which it refers. If the argument has a negative value, then it is equivalent to the corresponding positive value with the "-" flag.

The `[width]` specifier can be omitted.

#### Precision
The actions of the specifier `[precision]` depends on the type of the output number:

- For types d, i, u, x, X defines the minimum number of output digits. If the number of output digits in the number is less than specified in the `[precision]` specifier, then the output number will be padded with zeros on the left. For example, if you specify the precision of 4 when displaying the number 126, the number 0126 will be displayed on the screen

The precision is specified as a `dot` character followed by a decimal number or a "*" character, followed by the name of an int variable containing the precision value before the argument to which it refers.

The `[precision]` specifier can be omitted.


## How to use
Run `make` to compile the **libftprintf** library.

```
$>make
libftprintf.a:   object files are created 
libftprintf.a:   libftprintf.a created
libftprintf.a
```
Run `make bonus` to compile the **libftprintf** library with bonus flags for `ft_printf`.

The makefile also contains the rules `clean` - delete object files, `fclean` - delete everything, including libftprintf.a, and `re` - delete everything, including libftprintf.a and compile again.

Run `make test` to run tests for the main part or run `make test_b` for the bonus part.

**[Project instructions](https://github.com/AGolz/ft_printf-42/files/10759004/en.subject.pdf)**

Need help: emaksimo@student.42yerevan.am

Special thanks: [tripouille](https://github.com/Tripouille) for the [printfTester](https://github.com/Tripouille/printfTester) (:
