<?php

/* Redirection and Domain normalization for NON-SSL UCB sites */
// Replace EXAMPLE and EXAMPLE-OTHERNAME below!
// This code should go at the end of your settings.php


if (isset($_SERVER['PANTHEON_ENVIRONMENT'])) {
  if ($_SERVER['PANTHEON_ENVIRONMENT'] == 'live') {
  // Assumes hostmaster has setup EXAMPLE.berkeley.edu for you, or you are using your /etc/hosts

//Single domain name - Uncomment below when ready to deploy
/*
    $base_url = 'http://EXAMPLE.berkeley.edu';  // NO trailing slash!
    if ($_SERVER['HTTP_HOST'] == 'live-EXAMPLE.pantheon.berkeley.edu') {
      header('HTTP/1.0 301 Moved Permanently');
      header('Location: ' . $base_url . $_SERVER['REQUEST_URI']);
      exit();
    }
*/

//Multiple domain names - Uncomment below when ready to deploy
/*
    $base_url = 'http://EXAMPLE.berkeley.edu';  // NO trailing slash!
    if ($_SERVER['HTTP_HOST'] == 'live-EXAMPLE.pantheon.berkeley.edu'

    //Add (with logical OR) other domain names
    //copy and paste the line below once for each other domain
    || $_SERVER['HTTP_HOST'] == 'EXAMPLE-OTHERNAME.berkeley.edu'

    )
    //no need to edit the next bracketed section
    {
      header('HTTP/1.0 301 Moved Permanently');
      header('Location: ' . $base_url . $_SERVER['REQUEST_URI']);
      exit();
    }
*/

    //Single redirect - see http://helpdesk.getpantheon.com/customer/portal/articles/368354
    //Uncomment below if you want to use and then edit accordingly
    /*
    elseif ($_SERVER['HTTP_HOST'] == 'EXAMPLE-OTHERNAME.berkeley.edu') {
      $new_url = 'http://EXAMPLE.berkeley.edu/path/to/page';  // NO trailing slash!
      header('HTTP/1.0 301 Moved Permanently');
      header('Location: ' . $new_url);
      exit();
    }
    */
  }
}
