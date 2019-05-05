<html>
<body>
<?php
/* ASSOCIATIVE ARRAYS: similar to numeric array.
Their INDEX will be represented as a STRING , so that
you can establish a strong association between keys and
values. */
/*First method to associate create array. */
$salaries = array("mohammad" => 2000,
                  "qadir" => 1000,
                  "zara" => 500);
echo "Salary of mohammad is " . $salaries['mohammad'] . "<br />";
echo "Salary of qadir is " . $salaries['qadir'] . "<br />";
echo "Salary of zara is " . $salaries['zara'] . "<br />";

/* Second method to create array. */

$salaries['mohammad'] = "2000";
$salaries['qadir'] = "1000";
$salaries['zara'] = "500";

echo "Salary of mohammad is " . $salaries['mohammad'] . "<br />";
echo "Salary of qadir is " . $salaries['qadir'] . "<br />";
echo "Salary of zara is " . $salaries['zara'] . "<br />";


 ?>

</body>

</html>
