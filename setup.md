---
layout: page
title: Setup
description: Setup the skin
image: assets/images/Setup.png
nav-menu: true
id: 3
---

<div id="main" class="alt">

<section id="one">
		<div class="inner">
			<header class="major">
        <h1>Setup</h1>
      </header>

			<section id="toc">
				<h3>Table of Contents</h3>
				<ul class="list">
				  <li><a href="#stepOne">Setting up Google Play Music Desktop Player</a></li>
				  <li><a href="#stepOne">Authorizing the GPMDP Rainmeter plugin</a></li>
				  <li><a href="#stepOne">Troubleshooting</a></li>
				</ul>
			</section>

			<section id="stepOne">
				<div class="step">
				  <h2>Setting up Google Play Music Desktop Player</h2>
				  <p>If you haven't already, the skin is can be downloaded as a <i>.rmskin</i> package, <a href="https://github.com/JonSn0w/PlayMusic/releases/download/v1.2.1/PlayMusic_v1.2.1.rmskin">here</a>. In order for this skin to function properly, you must also install <strong><a href="https://googleplaymusicdesktopplayer.com">Google Play Music Desktop Player</a></strong>. <br/>
				  After installation, you'll then want to navigate to the applications <strong>Desktop Settings</strong>. You must then ensure that <i>Enable Playback API</i> and <i>Enable JSON API</i> are selected, as featured in the image below.</p>
				  <div id="settings-img" class="image">
				    <img src="assets/images/DesktopSettings.png" alt="Desktop Settings" width="750"/>
				  </div>
				</div>
			</section>
			<hr id="divider"/>

			<section id="stepTwo">
				<div class="step">
				  <h2>Authorizing the GPMDP Rainmeter plugin</h2>
				  <p>While the inclusion of media controls into <strong>PlayMusic</strong> has been requested since the initial release, remote functionalities have been impossible until the recent release of <strong><a href="https://github.com/tjhrulz/GPMDP-Plugin">GPMDP-Plugin</a></strong> by <a href="https://github.com/tjhrulz/GPMDP-Plugin">tjhrulz</a>, which cleverly uses the GPMDP web-socket to allow remote control of the application. Though, this plugin requires authorization via the GPMDP application. To make this process as easy as straightforward as possible, a supplementary authorization skin has been included in PlayMusic. As shown below, the skin features an input for the four-digit code provided by the application and a prompt that provides confirmation of the skins state.</p>
				  <div id="settings-img" class="image">
						<img src="assets/images/auth1.png" alt="No connection" width="400"/>
				    <img src="assets/images/auth2.png" alt="Connected" width="400"/>
				  </div>
				</div>
			</section>
			<hr id="divider"/>

			<section id="stepThree">
				<div class="step">
				  <h2>Troubleshooting</h2>
				  <p></p>
				</div>
			</section>

		</div>
	</section>
</div>
