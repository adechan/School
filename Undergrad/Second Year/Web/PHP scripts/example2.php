<html>
<body>

<!-- The following example makes five iterations and changes the assigned
 value of two variables on each pass of the loop  -->
<?php
 $a = 0;
 $b = 0;

 for ($i = 0; $i < 5; $i++)
 {
   $a += 10;
   $b += 5;
 }

 echo("At the end of the loop a = $a and b = $b");
 ?>
</body>

</html>
