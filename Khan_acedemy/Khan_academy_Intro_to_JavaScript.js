<!DOCTYPE html>
<html>
<head>
  <title>Hello Web - Processing.js Test</title>
  <script src="processing.js"></script>
</head>
<body>
  <h1>Processing.js Test</h1>
  <p>This is my first Processing.js web-based sketch:</p>
  <canvas id="canvas"></canvas>
   <script>
   function sketchProc(processing) {

      processing.draw = function() {
      var centerX = processing.width / 2, centerY = processing.height / 2;
      var maxArmLength = Math.min(centerX, centerY);
      function drawArm(position, lengthScale, weight) {
         processing.strokeWeight(weight);
         processing.line(centerX, centerY,
         centerX + Math.sin(position * 2 * Math.PI) * lengthScale * maxArmLength,
         centerY - Math.cos(position * 2 * Math.PI) * lengthScale * maxArmLength);
      }

      processing.background(224);
      var now = new Date();
      var hoursPosition = (now.getHours() % 12 + now.getMinutes() / 60) / 12;
      drawArm(hoursPosition, 0.5, 5);
      var minutesPosition = (now.getMinutes() + now.getSeconds() / 60) / 60;
      drawArm(minutesPosition, 0.80, 3);
      var secondsPosition = now.getSeconds() / 60;
      drawArm(secondsPosition, 0.90, 1);
      };
   }

   var canvas = document.getElementById("canvas");
   var processingInstance = new Processing(canvas, sketchProc);
   </script>
</body>
</html>