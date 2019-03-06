function Hello()
{
    document.getElementById("demo").innerHTML = "Hello, Javascript!";
}

function TurnOn()
{
  // document.getElementById("myImage").src = "pic_bulbon.gif";
 var image = document.getElementById("myImage");
 image.src = "pic_bulbon.gif";
}

function TurnOff()
{
  // document.getElementById("myImage").src = "pic_bulboff.gif";
  var image = document.getElementById("myImage");
  image.src = "pic_bulboff.gif";
}
