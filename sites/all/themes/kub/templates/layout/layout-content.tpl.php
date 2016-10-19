<div class="row">
  <div <?php print $content_attributes ?>>
    <div id="content-top">
      <?php if (!empty($messages)): ?>
        <?php print $messages ?>
      <?php endif; ?>
    </div>
    <div id="content-middle">
      <?php if (!empty($title)): ?>
        <div class="page-header">
          <h1><?php print $title ?></h1>
        </div>
      <?php endif; ?>
      <?php if (!empty($tabs)): ?>
        <div class="tabs"><?php print $tabs ?></div>
      <?php endif; ?>
      <?php if (!empty($help)): ?>
        <div class="well well-sm">
          <?php print $help; ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($page['content'])): ?>
        <?php print render($page['content']) ?>
      <?php endif; ?>
    </div>
    <div id="content-bottom">
      <?php if (!empty($breadcrumb)): ?>
        <div class="breadcrumb-wrap">
          <?php print $breadcrumb ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
  <?php if (!empty($sidebar)): ?>
    <div class="col-lg-4 col-md-4 col-sm-4 col-xs-12">
      <?php print $sidebar ?>
    </div>
  <?php endif; ?>
</div>

