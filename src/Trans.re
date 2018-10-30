[@bs.module "react-i18next"] external reactClass: ReasonReact.reactClass = "Trans";

/*
 i18nKey    string (undefined)  is optional if you prefer to use text as keys you can omit that and the translation will be used as a key.
 count  integer (undefined) optional count if you use a plural
 parent node (undefined)    a component to wrap the content into (default none, can be globally set on i18next.init) -> needed for react < v16
 i18n   object (undefined)
 i18next instance to use if not provided via context (using hoc or render props)
 t  function (undefined)   t function to use if not provided via context (using hoc or render props)
 defaults   string (undefined)  use this instead of default content in children (useful when using ICU)
 values object (undefined)  interpolation values if not provided in children
 components array[nodes] (undefined)    components to interpolate based on index of tag <0></0>, ...
 */

[@bs.obj]
external makeProps:
  (
    ~i18nKey: string=?,
    ~count: int=?,
    ~defaults: string=?,
    ~values: Js.Dict.t(string)=?,
    ~components: array(ReasonReact.reactElement)=?,
    unit
  ) =>
  _ =
  "";

let make = (~i18nKey=?, ~count=?, ~defaults=?, ~values=?, ~components=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~i18nKey?,
        ~count?,
        ~defaults?,
        ~values=?Js.Option.map((. b) => Js.Dict.fromList(b), values),
        ~components=?Js.Option.map((. b) => Array.of_list(b), components),
        (),
      ),
    children,
  );
