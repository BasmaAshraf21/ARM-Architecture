<?php

if ( isset($_GET['status']) )
{
	/* Open the file */
	$myfile = fopen("status.txt","w");
	
	if( $_GET['status'] == 'on')
	{
		fwrite($myfile, '1');
		echo ("LED On");
		header ("Location: on.html");
	}
	
	elseif ($_GET['status'] == 'off')
	{
		fwrite($myfile, '0');
		echo ("LED Off");
		header ("Location: off.html");
	}
	/* Close the File*/
	fclose($myfile);
}


?>