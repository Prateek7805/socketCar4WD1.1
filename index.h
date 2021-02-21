const char html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale = 1">
    <link rel="stylesheet" href="styles.css">
    <title>Socket car</title>
  </head>
  <body>
    <div class="container">
      <div class="header generalWidth center">
        <div class="generalWidth center">
          <div class="d-ib w-25">

          </div>
          <div class="d-ib w-50">
              <p class="title generalWhite center">Socket Car</p>
          </div>

          <div class="d-ib w-25">
            <label class="switch f-right">
            <input id="flag_settings" type="checkbox">
            <span class="slider round"></span>
            </label>
        </div>
      </div>

      </div>

      <div id="controller" class="content center">
        <div class="buttons">
          <div class="row center">
            <button id="forward" class="generalButton">&#8593;</button>
          </div>
          <div class="row center">
            <button id="left" class="generalButton">&#8592;</button><button id="stop" class="generalButton">S</button><button id="right" class="generalButton">&#8594;</button>
          </div>
          <div class="row center">
            <button id="backward" class="generalButton">&#8595;</button>
          </div>
        </div>
        <div class="range center">
            <input type="range" id="range" class="generalRange" min="0" max="1023" value="0" step="1"><span class="generalWhite" id="rangeVal">0</span>
        </div>
      </div>

      <div id="settings" class="content center d-none">
        <div class="buttons">

          <div class="card center">
            <h2 class="generalWhite">WiFi Mode</h2>
            <h3 class="generalWhite"><span class="dot bg-green"></span> AP</h3>
            <h3 class="generalWhite"><span class="dot bg-blue"></span> STA</h3>
            <label class="switch">
            <input id="wiFiMODE" type="checkbox">
            <span class="slider round"></span>
            </label>
          </div>

          <div class="card center">
            <h2 class="generalWhite">Auto Off</h2>
            <h3 class="generalWhite"><span class="dot bg-green"></span> ON</h3>
            <h3 class="generalWhite"><span class="dot bg-blue"></span> OFF</h3>
            <h4 class="generalWhite">10 min after inactivity</h4>
            <label class="switch">
            <input id="autoOff" type="checkbox">
            <span class="slider round"></span>
            </label>
          </div>

          <div class="card center">
            <h2 class="generalWhite">Restart</h2>
            <h4 class="generalWhite">This will restart the Car</h4>
            <button id="restart" class="center generalButtonCircle">R</button>
          </div>

          <div class="card center">
            <h2 class="generalWhite">AP Mode Password</h2>
            <h4 id="AP_er" class="generalWhite"></h4>
            <input id="AP_SSID" type="text" placeholder="SSID" class="generalInput" value="" required>
            <input id="AP_PASS" type="password" placeholder="Password" class="generalInput" value="" required>

            <button id="AP_submit" class="generalSubmitButton">Enter</button>
          </div>


        </div>
      </div>

    </div>
    <script src="script.js"></script>
  </body>
</html>

)=====";