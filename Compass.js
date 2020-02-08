import Mathjs;
bearing(rlat, rlon, llat, llon){
  var y = Math.sin(rlon-llon) * Math.cos(rlat);
  var x = Math.cos(llat)*Math.sin(rlat) -
          Math.sin(llat)*Math.cos(rlat)*Math.cos(rlon-llon);
  var brng = Math.atan2(y, x).toDegrees();
  return brng;
}
