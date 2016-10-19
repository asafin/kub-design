<?php

/**
 * @file Control panel fields from User module
 */

/**
 * User module settings
 *
 * @param $form
 * @param $form_state
 */
function cpanel_form_user(&$form, &$form_state) {
  $form["email_title"] = [
    "#type" => "item",
    "#title" => t("User mail texts"),
    "#weight" => 9,
  ];

  $form["email_settings"] = [
    "#type" => "vertical_tabs",
    "#weight" => 10,
  ];

  $email_token_help = t("Available variables are: [site:name], [site:url], [user:name], [user:mail], [site:login-url], [site:url-brief], [user:edit-url], [user:one-time-login-url], [user:cancel-url].");

  $form["email_admin_created"] = [
    "#type" => "fieldset",
    "#title" => t("Welcome (new user created by administrator)"),
    "#collapsible" => TRUE,
    "#collapsed" => (variable_get("user_register", USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL) != USER_REGISTER_ADMINISTRATORS_ONLY),
    "#description" => t("Edit the welcome e-mail messages sent to new member accounts created by an administrator.") . " " . $email_token_help,
    "#group" => "email_settings",
  ];

  $form["email_admin_created"]["user_mail_register_admin_created_subject"] = [
    "#type" => "textfield",
    "#title" => t("Subject"),
    "#default_value" => _user_mail_text("register_admin_created_subject", NULL, [], FALSE),
    "#maxlength" => 180,
  ];

  $form["email_admin_created"]["user_mail_register_admin_created_body"] = [
    "#type" => "textarea",
    "#title" => t("Body"),
    "#default_value" => _user_mail_text("register_admin_created_body", NULL, [], FALSE),
    "#rows" => 15,
  ];

  $form["email_pending_approval"] = [
    "#type" => "fieldset",
    "#title" => t("Welcome (awaiting approval)"),
    "#collapsible" => TRUE,
    "#collapsed" => (variable_get("user_register", USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL) != USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL),
    "#description" => t("Edit the welcome e-mail messages sent to new members upon registering, when administrative approval is required.") . " " . $email_token_help,
    "#group" => "email_settings",
  ];

  $form["email_pending_approval"]["user_mail_register_pending_approval_subject"] = [
    "#type" => "textfield",
    "#title" => t("Subject"),
    "#default_value" => _user_mail_text("register_pending_approval_subject", NULL, [], FALSE),
    "#maxlength" => 180,
  ];

  $form["email_pending_approval"]["user_mail_register_pending_approval_body"] = [
    "#type" => "textarea",
    "#title" => t("Body"),
    "#default_value" => _user_mail_text("register_pending_approval_body", NULL, [], FALSE),
    "#rows" => 8,
  ];

  $form["email_no_approval_required"] = [
    "#type" => "fieldset",
    "#title" => t("Welcome (no approval required)"),
    "#collapsible" => TRUE,
    "#collapsed" => (variable_get("user_register", USER_REGISTER_VISITORS_ADMINISTRATIVE_APPROVAL) != USER_REGISTER_VISITORS),
    "#description" => t("Edit the welcome e-mail messages sent to new members upon registering, when no administrator approval is required.") . " " . $email_token_help,
    "#group" => "email_settings",
  ];

  $form["email_no_approval_required"]["user_mail_register_no_approval_required_subject"] = [
    "#type" => "textfield",
    "#title" => t("Subject"),
    "#default_value" => _user_mail_text("register_no_approval_required_subject", NULL, [], FALSE),
    "#maxlength" => 180,
  ];

  $form["email_no_approval_required"]["user_mail_register_no_approval_required_body"] = [
    "#type" => "textarea",
    "#title" => t("Body"),
    "#default_value" => _user_mail_text("register_no_approval_required_body", NULL, [], FALSE),
    "#rows" => 15,
  ];

  $form["email_password_reset"] = [
    "#type" => "fieldset",
    "#title" => t("Password recovery"),
    "#collapsible" => TRUE,
    "#collapsed" => TRUE,
    "#description" => t("Edit the e-mail messages sent to users who request a new password.") . " " . $email_token_help,
    "#group" => "email_settings",
    "#weight" => 10,
  ];

  $form["email_password_reset"]["user_mail_password_reset_subject"] = [
    "#type" => "textfield",
    "#title" => t("Subject"),
    "#default_value" => _user_mail_text("password_reset_subject", NULL, [], FALSE),
    "#maxlength" => 180,
  ];

  $form["email_password_reset"]["user_mail_password_reset_body"] = [
    "#type" => "textarea",
    "#title" => t("Body"),
    "#default_value" => _user_mail_text("password_reset_body", NULL, [], FALSE),
    "#rows" => 12,
  ];

  $form["email_activated"] = [
    "#type" => "fieldset",
    "#title" => t("Account activation"),
    "#collapsible" => TRUE,
    "#collapsed" => TRUE,
    "#description" => t("Enable and edit e-mail messages sent to users upon account activation (when an administrator activates an account of a user who has already registered, on a site where administrative approval is required).") . " " . $email_token_help,
    "#group" => "email_settings",
  ];

  $form["email_activated"]["user_mail_status_activated_notify"] = [
    "#type" => "checkbox",
    "#title" => t("Notify user when account is activated."),
    "#default_value" => variable_get("user_mail_status_activated_notify", TRUE),
  ];

  $form["email_activated"]["settings"] = [
    "#type" => "container",
    "#states" => [
      // Hide the additional settings when this email is disabled.
      "invisible" => [
        "input[name=\"user_mail_status_activated_notify\"]" => ["checked" => FALSE],
      ],
    ],
  ];

  $form["email_activated"]["settings"]["user_mail_status_activated_subject"] = [
    "#type" => "textfield",
    "#title" => t("Subject"),
    "#default_value" => _user_mail_text("status_activated_subject", NULL, [], FALSE),
    "#maxlength" => 180,
  ];

  $form["email_activated"]["settings"]["user_mail_status_activated_body"] = [
    "#type" => "textarea",
    "#title" => t("Body"),
    "#default_value" => _user_mail_text("status_activated_body", NULL, [], FALSE),
    "#rows" => 15,
  ];

  $form["email_blocked"] = [
    "#type" => "fieldset",
    "#title" => t("Account blocked"),
    "#collapsible" => TRUE,
    "#collapsed" => TRUE,
    "#description" => t("Enable and edit e-mail messages sent to users when their accounts are blocked.") . " " . $email_token_help,
    "#group" => "email_settings",
  ];

  $form["email_blocked"]["user_mail_status_blocked_notify"] = [
    "#type" => "checkbox",
    "#title" => t("Notify user when account is blocked."),
    "#default_value" => variable_get("user_mail_status_blocked_notify", FALSE),
  ];

  $form["email_blocked"]["settings"] = [
    "#type" => "container",
    "#states" => [
      // Hide the additional settings when the blocked email is disabled.
      "invisible" => [
        "input[name=\"user_mail_status_blocked_notify\"]" => ["checked" => FALSE],
      ],
    ],
  ];

  $form["email_blocked"]["settings"]["user_mail_status_blocked_subject"] = [
    "#type" => "textfield",
    "#title" => t("Subject"),
    "#default_value" => _user_mail_text("status_blocked_subject", NULL, [], FALSE),
    "#maxlength" => 180,
  ];

  $form["email_blocked"]["settings"]["user_mail_status_blocked_body"] = [
    "#type" => "textarea",
    "#title" => t("Body"),
    "#default_value" => _user_mail_text("status_blocked_body", NULL, [], FALSE),
    "#rows" => 3,
  ];

  $form["email_cancel_confirm"] = [
    "#type" => "fieldset",
    "#title" => t("Account cancellation confirmation"),
    "#collapsible" => TRUE,
    "#collapsed" => TRUE,
    "#description" => t("Edit the e-mail messages sent to users when they attempt to cancel their accounts.") . " " . $email_token_help,
    "#group" => "email_settings",
  ];

  $form["email_cancel_confirm"]["user_mail_cancel_confirm_subject"] = [
    "#type" => "textfield",
    "#title" => t("Subject"),
    "#default_value" => _user_mail_text("cancel_confirm_subject", NULL, [], FALSE),
    "#maxlength" => 180,
  ];

  $form["email_cancel_confirm"]["user_mail_cancel_confirm_body"] = [
    "#type" => "textarea",
    "#title" => t("Body"),
    "#default_value" => _user_mail_text("cancel_confirm_body", NULL, [], FALSE),
    "#rows" => 3,
  ];

  $form["email_canceled"] = [
    "#type" => "fieldset",
    "#title" => t("Account canceled"),
    "#collapsible" => TRUE,
    "#collapsed" => TRUE,
    "#description" => t("Enable and edit e-mail messages sent to users when their accounts are canceled.") . " " . $email_token_help,
    "#group" => "email_settings",
  ];

  $form["email_canceled"]["user_mail_status_canceled_notify"] = [
    "#type" => "checkbox",
    "#title" => t("Notify user when account is canceled."),
    "#default_value" => variable_get("user_mail_status_canceled_notify", FALSE),
  ];

  $form["email_canceled"]["settings"] = [
    "#type" => "container",
    "#states" => [
      // Hide the settings when the cancel notify checkbox is disabled.
      "invisible" => [
        "input[name=\"user_mail_status_canceled_notify\"]" => ["checked" => FALSE],
      ],
    ],
  ];

  $form["email_canceled"]["settings"]["user_mail_status_canceled_subject"] = [
    "#type" => "textfield",
    "#title" => t("Subject"),
    "#default_value" => _user_mail_text("status_canceled_subject", NULL, [], FALSE),
    "#maxlength" => 180,
  ];

  $form["email_canceled"]["settings"]["user_mail_status_canceled_body"] = [
    "#type" => "textarea",
    "#title" => t("Body"),
    "#default_value" => _user_mail_text("status_canceled_body", NULL, [], FALSE),
    "#rows" => 3,
  ];
}
