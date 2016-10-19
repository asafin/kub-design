<div class="row">
  <div class="col-sm-4 col-xs-6 footer-col footer-col_left">
    <?php if (!empty($site_slogan)): ?>
      <div class="site-slogan">
        <?php print $site_slogan ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($site_copyright)): ?>
      <div class="copyright">
        <?php print $site_copyright ?>
      </div>
    <?php endif; ?>
  </div>
  <div class="col-sm-4 col-xs-6 footer-col footer-col_middle">
    <?php if (!empty($footer_message)): ?>
      <div class="footer-message">
        <?php print $footer_message ?>
      </div>
    <?php endif; ?>
    <div class="footer-email">
      <?php print $footer_email ?>
    </div>
  </div>
  <div class="col-lg-3 footer-col footer-col_right">
    <?php print $sitemap_link ?>
  </div>
</div>
<!-- BEGIN MARVA-MODULE -->
<script type='text/javascript'>//<![CDATA[
  if(typeof(marva)=='undefined'||marva==null){marva={};}if(!marva.load_async){marva.load_async=function(src,callback){if(callback=='undefined'||callback==null){callback=function(){};}var sc=document.createElement("script");sc.charset="windows-1251";sc.type="text/javascript";sc.setAttribute("async","true");sc.src=(document.location.protocol=='https:'?"https:":"http:")+"//"+src;if(sc.readyState){sc.onreadystatechange=function(){if(sc.readyState=="loaded"||sc.readyState=="complete"){sc.onreadystatechange=null;callback();}}}else{sc.onload=function(){callback();};}window.onload=new function(){document.documentElement.firstChild.appendChild(sc);};}}
  marva.load_async("account.marva.ru/js/rh.asp?l=astorastor&x=1002921&deptid=0&rnd="+Math.floor(Math.random()*1000000000));
  //]]>
</script><!-- END MARVA-MODULE -->