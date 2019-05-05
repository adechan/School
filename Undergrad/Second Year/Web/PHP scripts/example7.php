<html>
<body>
<?php
/* MULTIDIMENSIONAL ARRAY: each element in the main array
can also be an array. And each element in the sub-ARRAY
can be an array. */
$marks = array(
  "mohammad" => array (
    "physics" => 35,
    "maths" => 30,
    "chemistry" => 39
  ),

  "qadir" => array (
    "physics" => 30,
    "maths" => 38,
    "chemistry" => 20
  ),

  "zara" => array (
    "physics" => 38,
    "maths" => 32,
    "chemistry" => 28
  )
);

echo "Marks for mohammad in physics: ";
echo $marks['mohammad']['physics'] . "<br />";

echo "Marks for qadir in physics: ";
echo $marks['qadir']['physics'] . "<br />";

echo "Marks for zara in physics: ";
echo $marks['zara']['physics'] . "<br />";
 ?>

</body>

</html>
