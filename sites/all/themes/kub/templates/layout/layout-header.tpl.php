<div class="header-top">
  <div class="row">
    <div class="col-xs-6">
      <?php print $logo ?>
    </div>
    <div class="col-xs-6">
      <?php if (!empty($header_phone)): ?>
        <div class="header-phone">
          <div class="header-phone__content">
            <?php print $header_phone ?>
          </div>
<!--          <div class="header-phone__title">-->
<!--            Живой человек лучше робота!-->
<!--          </div>-->
        </div>
      <?php endif; ?>
    </div>
  </div>
</div>
<?php if (!empty($navigation)): ?>
  <div class="header-bottom">
    <div class="row">
      <div class="col-lg-12 col-md-12 col-sm-12">
        <nav class="navbar navbar-default main-menu">
          <div class="container-fluid">
            <div class="navbar-header">
              <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#main-menu-wrap" aria-expanded="false">
                <span class="sr-only">Toggle navigation</span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
              </button>
              <?php print $home_link ?>
            </div>
            <div class="collapse navbar-collapse" id="main-menu-wrap">
              <?php print $navigation ?>
            </div>
          </div>
        </nav>
      </div>
    </div>
  </div>
<?php endif; ?>
