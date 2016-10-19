<?php
/**
 * @var string $sidebar
 * @var string $header
 * @var string $content
 * @var string $footer
 */
?>
<div id="body-wrap" class="container">
  <div class="row">
    <div class="col-lg-12 col-md-12 col-sm-12">
      <header id="header-wrap">
        <?php print $header ?>
      </header>
      <div id="content-wrap">
        <?php print $content ?>
      </div>
      <footer id="footer-wrap">
        <?php print $footer ?>
      </footer>
    </div>
  </div>
</div>