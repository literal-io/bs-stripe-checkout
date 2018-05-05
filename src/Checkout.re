type t;

[@bs.val] external inst : t = "StripeCheckout";

/* FIXME: type */
type checkoutArgs = {.};

type token = {
  .
  "id": string,
  "email": string
};

type params = {
  .
  "key": Js.nullable(string),
  "token": Js.nullable((token, checkoutArgs) => unit),
  "name": Js.nullable(string),
  "image": Js.nullable(string),
  "locale": Js.nullable(string),
  "description": Js.nullable(string),
  "amount": Js.nullable(string),
  "zipCode": Js.nullable(bool),
  "billingAddress": Js.nullable(bool),
  "currency": Js.nullable(string),
  "panelLabel": Js.nullable(string),
  "shippingAddress": Js.nullable(bool),
  "email": Js.nullable(string),
  "label": Js.nullable(string),
  "allowRememberMe": Js.nullable(bool),
  "opened": Js.nullable(unit => unit),
  "closed": Js.nullable(unit => unit)
};

[@bs.obj]
external makeParams :
  (
    ~key: string=?,
    ~token: (token, checkoutArgs) => unit=?,
    ~name: string=?,
    ~image: string=?,
    ~locale: string=?,
    ~description: string=?,
    ~amount: string=?,
    ~zipCode: bool=?,
    ~billingAddress: bool=?,
    ~currency: string=?,
    ~panelLabel: string=?,
    ~shippingAddress: string=?,
    ~email: string=?,
    ~label: string=?,
    ~allowRememberMe: bool=?,
    ~opened: unit => unit=?,
    ~closed: unit => unit=?,
    unit
  ) =>
  params =
  "";

[@bs.send.pipe : t] external configure : params => unit = "";

[@bs.send.pipe : t] external open_ : params => unit = "open";