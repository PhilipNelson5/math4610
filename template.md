---
title: <++>
layout: default
---
<a href="https://philipnelson5.github.io/math4610/SoftwareManual"> Table of Contents </a>
# <++> Software Manual
This is a template file for building an entry in the student software manual project. You should use the formatting below to
define an entry in your software manual.

**Routine Name:** <++>

**Author:** Philip Nelson

**Language:** C++. The code can be compiled using the GNU C++ compiler (gcc). A make file is included to compile an example program

For example,

```
make
```

will produce an executable **./<++> .out** that can be executed.

**Description/Purpose:** This routine will compute the single precision value for the machine epsilon or the number of digits
in the representation of real numbers in single precision. This is a routine for analyzing the behavior of any computer. This
usually will need to be run one time for each computer.

**Input:** There are no inputs needed in this case. Even though there are arguments supplied, the real purpose is to
return values in those variables.

**Output:** This routine returns a single precision value for the number of decimal digits that can be represented on the
computer being queried.

**Usage/Example:**

The routine has two arguments needed to return the values of the precision in terms of the smallest number that can be
represented. Since the code is written in terms of a Fortran subroutine, the values of the machine machine epsilon and
the power of two that gives the machine epsilon. Due to implicit Fortran typing, the first argument is a single precision
value and the second is an integer.

{% highlight c++ %}
<++>
{% endhighlight %}

**Output** from the lines above
```
<++>
```

_explanation of output_
<++>

**Implementation/Code:** The following is the code for <++>

{% highlight c++ %}
<++>
{% endhighlight %}

**Last Modified:** <++>September 2018