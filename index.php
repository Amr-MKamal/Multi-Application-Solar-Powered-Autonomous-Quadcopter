<?php error_reporting(0); ?>
<link rel="stylesheet" type="text/css" href="css/bootstrap.min.css"> 
<link rel="stylesheet" type="text/css" href="css/font-awesome.min.css">

<p class=" text-center badge">my control</p>
<div id="container">
<form>

<button value="1"  name="s1"><i class="fa fa-arrow-up"></i></button>
<div class="left-to-right">
	<button value="2"  name="s2"><i class="fa fa-arrow-left"></i></button>
	<button value="3"  name="s3"><i class="fa fa-arrow-right"></i></button>
</div>
<button value="4"  name="s4"><i class="fa fa-arrow-down"></i></button>


<div class="two-buttons">
	<button value="5"  name="s5"><i class="fa fa-refresh fa-5x"></i></button><br><br>
	<button value="6"  name="s6"><i class="fa fa-arrow-circle-up fa-4x"></i></button><br>
	<button value="7"  name="s7"><i class="fa fa-arrow-circle-down fa-4x"></i></button>
</div>




<div class="two-buttons">
	<button value="8"  name="s8"><i class="fa fa-plus-circle fa-4x"></i></button>
	<button value="9"  name="s9"><i class="fa fa-minus-circle fa-4x"></i></button>
</div>




<div class="two-buttons">
	<button value="10" name="s10">100</button>
	<button value="11" name="s11">255</button>
	<button value="12" name="s12">1000</button>
</div>


<div class="two-buttons">
	<button value="13" name="s13"><i class="fa fa-power-off"></i></button>
	<button value="14" name="s14"><i class="fa fa-power-off"></i></button>
</div>

</form>
</div>





<?php
	$parameter = $_SERVER['QUERY_STRING'];
	$val = explode('=', $parameter)[1];

	if ($val != ''){ exec('./quad v0 .exe ' . $val);}
 ?>


 <style type="text/css">
 button{
 	background-color: rgba(243,156,18,.001);
 }

button[name=s1]{
	display: block;
	color: black;
	min-width: 50px;
	min-height: 50px;
	border-radius: 50%;
	font-size: 33px;
}
.left-to-right {
	min-width: 50px;
	min-height: 50px;
	text-align: center;

}
.left-to-right button{
	min-width: 55px;
	min-height: 55px;
	border-radius: 50%;
	font-size: 33px;
}
.left-to-right button[name=s3]
{
	margin-left: 55px;
}

button[name=s4]{
	color: black;
	min-width: 50px;
	min-height: 50px;
	display: block;
	border-radius: 50%;
	font-size: 33px;
}
button{
	margin-top: 55px;
	color: #34495e;
	min-width: 50px;
	min-height: 50px;
	margin: 0 auto;
	min-width: 50px;
	min-height: 10px;
	border-radius: 75px;
}
button[name=s7]{
	margin-top: 7px;

}

button[name=s13]{
	color: darkblue;
	font-weight: 900;
	font-stretch: 20%;
		font-size: 30px;

}
button[name=s14]{
	color: #7f7c80;
	font-weight: 900;
	font-size: 30px;

}

.two-buttons{
	margin: 0 auto;
	text-align: center;
	padding-top: 10px;
}
.two-buttons button{
	font-weight: 900;
	text-align: center;
}



#container{
	width: 66%;
	background-color: rgba(255,255,255,0.95);
	margin: 0 auto;
	border-radius: 20px;
	box-shadow: 0 10px 20px rgba(0,0,0,0.19), 0 6px 6px rgba(0,0,0,0.55);

}

body{
	/*background-color: #7f7c80;*/
	background-image: url('bg.jpg');
	background-position: center;
	background-repeat: no-repeat;
	background-size:cover;
}
.badge{
	    max-width: 144px;
	    margin: 0 auto;
	    display: block;
	    font-size: 22px;
	    background-color: black
}


h1{
	font-size: 44px;
}


</style>
 